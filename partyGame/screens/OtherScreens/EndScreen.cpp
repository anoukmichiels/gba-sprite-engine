//
// Created by michi on 17/07/2020.
//
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "EndScreen.h"
#include "MainMenuScreen.h"
#include "../../backgrounds/standard/gras.h"
#include "../../backgrounds/standard/grasBackground.h"
#include "../../sound/win.h"

#include "../../Sprites/ghost_family_moving1.h"
#include "../../Sprites/ghost_family_moving2.h"
#include "../../Sprites/ghost_family_moving3.h"
#include "../../Sprites/ghost_family_moving4.h"
#include "../../Sprites/sharedEndScreen.h"

#include "../../Sprites/ghost_family_1.h"
#include "../../Sprites/ghost_family_2.h"
#include "../../Sprites/ghost_family_3.h"
#include "../../Sprites/ghost_family_4.h"
#include "../../Sprites/sharedGhost.h"



std::vector<Background *> EndScreen::backgrounds() {
    return {background.get()};
}

std::vector<Sprite *> EndScreen::sprites() {
    return {ghostFamily1.get(), ghostFamily2.get(), ghostFamily3.get(), ghostFamily4.get()};
}


void EndScreen::load() {

    TextStream::instance().setText(std::string("Yay! You made it!"), 1, 1);
    TextStream::instance().setText(std::string("Score: " + std::to_string(score)), 2, 1);

    TextStream::instance().setText(std::string("Press start for the main menu"), 10, 1);

    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(grasPal, sizeof(grasPal)));
    background = std::unique_ptr<Background>(new Background(1, grasTiles, sizeof(grasTiles), grasBackground, sizeof(grasBackground)));
    background->useMapScreenBlock(16);

    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedGhostPal, sizeof(sharedGhostPal)));
    SpriteBuilder<Sprite> spriteBuilder;
    ghostFamily1 = spriteBuilder
            .withData(ghost_family_1Tiles, sizeof(ghost_family_1Tiles))
            .withSize(SIZE_64_64)
            .withAnimated(1, 10)
            .withLocation(10, 10)
            .buildPtr();
    ghostFamily2 = spriteBuilder
            .withData(ghost_family_2Tiles, sizeof(ghost_family_2Tiles))
            .withSize(SIZE_64_64)
            .withAnimated(1, 10)
            .withLocation(74, 10)
            .buildPtr();
    ghostFamily3 = spriteBuilder
            .withData(ghost_family_3Tiles, sizeof(ghost_family_3Tiles))
            .withSize(SIZE_64_64)
            .withAnimated(1, 10)
            .withLocation(10, 74)
            .buildPtr();
    ghostFamily4 = spriteBuilder
            .withData(ghost_family_4Tiles, sizeof(ghost_family_4Tiles))
            .withSize(SIZE_64_64)
            .withAnimated(1, 10)
            .withLocation(74, 74)
            .buildPtr();


    engine->enqueueMusic(win, sizeof(win), 44100);
}

void EndScreen::tick(u16 keys) {

    if (firstTick) {
        firstTick = false;
        lastKeys = keys;
        return;
    }

    if (!(keys & KEY_START) && (lastKeys & KEY_START)) {
        engine->setScene(new MainMenuScreen(engine));
    }

    lastKeys = keys;


}
