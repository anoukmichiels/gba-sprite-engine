//
// Created by michi on 22/03/2020.
//

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "AboutScreen.h"
#include "MainMenuScreen.h"

#include "../../backgrounds/standard/gras.h"
#include "../../backgrounds/standard/grasBackground.h"

#include "../../Sprites/pijl.h"
#include "../../Sprites/wit_spook_1.h"
#include "../../Sprites/shared.h"



std::vector<Background *> AboutScreen::backgrounds() {
    return {background.get()};}


std::vector<Sprite *> AboutScreen::sprites() { return {pijl.get()};}

void AboutScreen::load() {

    TextStream::instance().setText("HOW TO PLAY", 1, 1);
    TextStream::instance().setText("Use the start key to", 3, 1);
    TextStream::instance().setText(" * accept options", 4, 1);
    TextStream::instance().setText(" * roll the dice", 5, 1);
    TextStream::instance().setText(" * catch the bad ghosts", 6, 1);
    TextStream::instance().setText("Use the arrow keys to", 8, 1);
    TextStream::instance().setText(" * select a different option", 9, 1);
    TextStream::instance().setText(" * walk around the board", 10, 1);
    TextStream::instance().setText("Back to the main menu", 17, 5);

    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(grasPal, sizeof(grasPal)));
    background = std::unique_ptr<Background>(new Background(1, grasTiles, sizeof(grasTiles), grasBackground, sizeof(grasBackground)));
    background->useMapScreenBlock(16);

    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    SpriteBuilder<Sprite> spriteBuilder;
    pijl = spriteBuilder
            .withData(pijlTiles, sizeof(pijlTiles))
            .withSize(SIZE_32_32)
            .withAnimated(1, 40)
            .withLocation(5, 126)
            .buildPtr();

}

void AboutScreen::tick(u16 keys) {
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