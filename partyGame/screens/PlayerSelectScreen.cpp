//
// Created by michi on 10/08/2020.
//

#include "PlayerSelectScreen.h"


#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>

#include "GameScreen.h"

#include "../backgrounds/MainMenu/pijl.h"
#include "../backgrounds/gras.h"
#include "../backgrounds/grasBackground.h"

std::vector<Background *> PlayerSelectScreen::backgrounds() {return {/*background.get()*/};}

std::vector<Sprite *> PlayerSelectScreen::sprites() {return{}/* {pijl.get(), spook1.get(), spook1.get()}*/;}

void PlayerSelectScreen::load() {
    TextStream::instance().setText(std::string("Choose Your player"), 2, 5);

    /*
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(pijlPal, sizeof(pijlPal)));
    SpriteBuilder<Sprite> spriteBuilder;
    pijl = spriteBuilder
            .withData(pijlTiles, sizeof(pijlTiles))
            .withSize(SIZE_32_32)
            .withAnimated(1, 40)
            .withLocation(5, 46)
            .buildPtr();

    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(grasPal, sizeof(grasPal)));
    background = std::unique_ptr<Background>(new Background(1, grasTiles, sizeof(grasTiles), grasBackground, sizeof(grasBackground)));
    background->useMapScreenBlock(16);*/
}

void PlayerSelectScreen::tick(u16 keys) {

    if (firstTick) {
        firstTick = false;
        lastKeys = keys;
        return;
    }/*

    if (!(keys & KEY_START) && (lastKeys & KEY_START)) {// ENTER key, wait until released
        if (spelerKeuze == 0) {
            if (!engine->isTransitioning()) {
                engine->transitionIntoScene(new GameScreen(engine), new FadeOutScene(2));
            }
        }
        else {
            engine->transitionIntoScene(new GameScreen(engine), new FadeOutScene(2));
        }
    }
    else if ((keys & KEY_DOWN) && !(lastKeys & KEY_DOWN)) {
        if (spelerKeuze == 0) {
            spelerKeuze++;
            updatePijl();
        }
    }
    else if ((keys & KEY_UP) && !(lastKeys & KEY_UP)) {
        if (spelerKeuze == 1) {
            spelerKeuze--;
            updatePijl();
        }
    }
    lastKeys = keys;*/
}
/*
void PlayerSelectScreen::updatePijl() {
    pijl->moveTo(5, 46 + spelerKeuze * 24);
}*/
