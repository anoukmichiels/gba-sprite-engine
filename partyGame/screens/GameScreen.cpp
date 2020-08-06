//
// Created by michi on 14/04/2020.
//

#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include "GameScreen.h"
//#include "../img/shared.h"
//#include "../img/speler1.h"
//#include "../img/spelerAI.h"
#include "../img/hoofdpersonage.h"
#include "MainMenuScreen.h"

#include "../backgrounds/Tiles8x8.h"
#include "../backgrounds/eerste7x7Map.h"
#include "../backgrounds/Background8x8Map.h"
#include "EndScreen.h"
#include "Minigame2Screen.h"

//#include "Minigame1Screen.h"


#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>



void GameScreen::load() {
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(Tiles8x8Pal, sizeof(Tiles8x8Pal)));
    background = std::unique_ptr<Background>(new Background(2, Tiles8x8Tiles, sizeof(Tiles8x8Tiles), eerste7x7Map, sizeof(eerste7x7Map)));
    background.get()->useMapScreenBlock(4);
    background2 = std::unique_ptr<Background>(new Background(1, Tiles8x8Tiles, sizeof(Tiles8x8Tiles), Background8x8Map, sizeof(Background8x8Map)));
    background2.get()->useMapScreenBlock(20);

    TextStream::instance().setText(std::string("Score"), 1, 25);
    //TextStream::instance().setText(std::string(std::to_string(gamePointer->getScore())), 2, 25);
    TextStream::instance().setText(std::string(std::to_string(game->getSpeler()->getScore())), 2, 25);
    TextStream::instance().setText(std::string("Zetten"), 3, 25);
    TextStream::instance().setText(std::string(std::to_string(game->getSpeler()->getVakjesNogVerschuiven())), 4, 25);
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(hoofdpersonagePal, sizeof(hoofdpersonagePal)));

    SpriteBuilder<Sprite> spriteBuilder;

    speler1Sprite = spriteBuilder
            .withData(hoofdpersonageTiles, sizeof(hoofdpersonageTiles))
            .withSize(SIZE_32_32)
            .withAnimated(1, 40)
            .withLocation(0, 0)
            .buildPtr();
    updatePosition();
}

std::vector<Sprite *> GameScreen::sprites() {
    return {speler1Sprite.get()};

}

std::vector<Background *> GameScreen::backgrounds() {
    return {background.get(), background2.get()};
}

void GameScreen::tick(u16 keys) {

    if (firstTick) {
        firstTick = false;
        lastKeys = keys;
        return;
    }

    if (!(keys & KEY_RIGHT) && (lastKeys & KEY_RIGHT)) {
        game->getSpeler()->beweegNaarRechts();
        updatePosition();
    }
    else if (!(keys & KEY_LEFT) && (lastKeys & KEY_LEFT)) {
        game->getSpeler()->beweegNaarLinks();
        updatePosition();
    }
    else if (!(keys & KEY_UP) && (lastKeys & KEY_UP)) {
        game->getSpeler()->beweegNaarBoven();
        updatePosition();
    }
    else if (!(keys & KEY_DOWN) && (lastKeys & KEY_DOWN)) {
        game->getSpeler()->beweegnaarOnder();
        updatePosition();
        if (game->getHuidigVakje() == 1) {
            TextStream::instance().clear();
            engine->setScene(new Minigame2Screen(engine, game));
        }
    }

    else if (!(keys & KEY_START) && (lastKeys & KEY_START)) {
        //engine->setScene(new MainMenuScreen(engine));
        game->getSpeler()->gooiDobbelsteen();
        updatePosition();
    }

    /*
    else if (!(keys & KEY_A) && (lastKeys & KEY_A)) {
        game->gooiDobbelsteen();
    }*/
    /*
    if (game.getSpeler1Y() == 0 and game.getSpeler1X() == 0) {
        //engine->setScene(new Minigame2Screen(engine, game));
        engine->setScene(new Minigame2Screen(engine, referenceGame));
        //game.setScore(10);
    }*/

   // if (game.getHuidigVakje() == 1 and !spelGespeeld) {
      //  //Game &referenceGame = game;
       // spelGespeeld = true;
       // engine->setScene(new Minigame2Screen(engine, game));

   // }

    if (game->getSpeler()->getPosX() == 3 and game->getSpeler()->getPosY() == 3) {
        //engine->setScene(new EndScreen(engine));
    }
    //updateSpeler1();
    //TextStream::instance().setText(std::string(std::to_string(game->getScore())), 2, 25);

    lastKeys = keys;
}
// Zoveel logica mag eigenlijk nooit in een update staan, wordt veel te vaak aangeroepen?
void GameScreen::updatePosition() {
    int bgX = 0; //Functies hieronder efficiënter schrijven!!
    int spX = 0;
    int bgY = 0;
    int spY = 0;

    switch (game->getSpeler()->getPosX()) {
        case 0: case 1: case 2:
            bgX = 0;
            break;
        case 3: case 4: case 5: case 6:
            bgX = 1;
            break;

    }
    switch (game->getSpeler()->getPosX()) {
        case 0:
            spX = 0;
            break;
        case 1:
            spX = 1;
            break;
        case 2: case 3:
            spX = 2;
            break;
        case 4:
            spX = 3;
            break;
        case 5:
            spX = 4;
            break;
        case 6:
            spX = 5;
            break;

    }

    switch (game->getSpeler()->getPosY()) {
        case 0: case 1: case 2:
            bgY = 0;
            break;
        case 3:
            bgY = 1;
            break;
            case 4: case 5: case 6:
            bgY = 2;
            break;
    }
    switch (game->getSpeler()->getPosY()) {
        case 0:
            spY = 0;
            break;
        case 1:
            spY = 1;
            break;
        case 2: case 3: case 4:
            spY = 2;
            break;
        case 5:
            spY = 3;
            break;
        case 6:
            spY = 4;
            break;
    }

    speler1Sprite.get()->moveTo(spX*32, spY*32);
    background.get()->scroll(bgX * 32,bgY*32);
    TextStream::instance().setText(std::string(std::to_string(game->getSpeler()->getVakjesNogVerschuiven())), 4, 25);

}




