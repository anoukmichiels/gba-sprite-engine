//
// Created by michi on 15/07/2020.
//

#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "MinigameScreen.h"
#include "../img/hoofdpersonage.h"
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "MainMenuScreen.h"
#include "GameScreen.h"

#include "../backgrounds/grasBackground.h"
#include "../backgrounds/gras.h"
#include "../backgrounds/gunshot.h"
#include "../backgrounds/picture1short.h"

#include "../backgrounds/Minigame/box.h"
#include "../backgrounds/Minigame/redEnemy.h"
#include "../backgrounds/Minigame/greenEnemy.h"
#include "../backgrounds/Minigame/blueEnemy.h"
#include "../backgrounds/Minigame/sharedMinigame.h"

MinigameScreen::MinigameScreen(std::shared_ptr<GBAEngine> engine, std::shared_ptr<Game> gamepje, int sprite) : Scene(engine), game(gamepje), spriteKeuze(sprite) {

}

void MinigameScreen::load() {
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(grasPal, sizeof(grasPal)));
    background = std::unique_ptr<Background>(new Background(1, grasTiles, sizeof(grasTiles), grasBackground, sizeof(grasBackground)));
    background.get()->useMapScreenBlock(16);

}
std::vector<Sprite *> MinigameScreen::sprites() {return {badGuy.get(), box.get()};}

std::vector<Background *> MinigameScreen::backgrounds() {return {background.get()};}

void MinigameScreen::tick(u16 keys) {

    if (firstTick) {
        setBegintekst();
        wachtEven(2000);
        removeTekst();
        firstTick = false;
        lastKeys = keys;
        return;
    }

    if (bezig) { // Als ik dit blok onder het andere zet geeft de updatePosition() problemen.
        minigame->beweeg();
        updatePosition();
    }

    if (!(keys & KEY_START) && (lastKeys & KEY_START)) {// ENTER key, wait until released
        bezig = false;
        endScene();
    }

    lastKeys = keys;
}

void MinigameScreen::updatePosition() {
   badGuy->moveTo(minigame->getPosX(), minigame->getPosY());
    TextStream::instance().setText(std::string("X: " + std::to_string(minigame->getPosX())), 1, 10);
    TextStream::instance().setText(std::string("Y: " + std::to_string(minigame->getPosY())), 2, 10);
    box->moveTo(minigame->getPosBoxX(), minigame->getPosBoxY());
}


void MinigameScreen::endScene() {
    minigame->makePicture();
    setGehaald();
    setEindtekst();
    wachtEven(2000);
    game->getSpeler()->setAlGegooid(false); //Moet dat hier of bij Minigame2.cpp*/
    engine->setScene(new GameScreen(engine, game, spriteKeuze));
}

void MinigameScreen::wachtEven(int tijd) {
    engine->getTimer()->stop();
    engine->getTimer()->reset();
    engine->getTimer()->start();
    while (engine->getTimer()->getTotalMsecs() < tijd) {}
    engine->getTimer()->stop();
    engine->getTimer()->reset();
}

void MinigameScreen::removeTekst() {
    TextStream::instance().clear();

}



