//
// Created by michi on 14/04/2020.
//

#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <random>
#include "GameScreen.h"

#include "../../Sprites/dobbelsteen.h"
#include "../../Sprites/wit_spook_1.h"
#include "../../Sprites/wit_spook_2.h"
#include "../../Sprites/blue_stone_with_border.h"
#include "../../Sprites/red_stone_with_border.h"
#include "../../Sprites/green_stone_with_border.h"
#include "../../Sprites/shared.h"

#include "../MinigameScreens/Minigame1Screen.h"
#include "../MinigameScreens/Minigame2Screen.h"
#include "../MinigameScreens/Minigame3Screen.h"
#include "../OtherScreens/EndScreen.h"





#include "../../backgrounds/gameScreen/gameScreenMap.h"



#include "../../backgrounds/gameScreen/gameScreenFull.h"
#include "../../backgrounds/gameScreen/gameScreenFull.c"

#include "../../backgrounds/gameScreen/transparantAndRedMap.h"


#include "../../backgrounds/GamescreenColours/rood.c"
#include "../../backgrounds/GamescreenColours/groen.c"
#include "../../backgrounds/GamescreenColours/blauw.c"
#include "../../backgrounds/GamescreenColours/roodEnGroen.c"
#include "../../backgrounds/GamescreenColours/roodEnBlauw.c"
#include "../../backgrounds/GamescreenColours/groenEnBlauw.c"
#include "../../backgrounds/GamescreenColours/wit.c"
#include "../../backgrounds/GamescreenColours/zwart.c"

#include "../../sound/gameScreenMusic.h"


void GameScreen::load() {

    if (game->getSpeler()->getSpel1Gehaald()) {
        if (game->getSpeler() ->getSpel2Gehaald()) {
            if (game->getSpeler()->getSpel3Gehaald()) {
                backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(
                        new BackgroundPaletteManager(gameScreenFullPalWit, sizeof(gameScreenFullPalWit)));
            } else {
                backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(
                        new BackgroundPaletteManager(gameScreenFullPalRoodEnGroen,
                                                     sizeof(gameScreenFullPalRoodEnGroen)));
            }
        }
        else {
            if (game->getSpeler()->getSpel3Gehaald())  {
                backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(gameScreenFullPalRoodEnBlauw, sizeof(gameScreenFullPalRoodEnGroen)));
            }
            else {
                backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(gameScreenFullPalRood, sizeof(gameScreenFullPalRood)));
            }
        }
    }
    else {
        if (game->getSpeler()->getSpel2Gehaald()) {
            if (game->getSpeler()->getSpel3Gehaald()) {
                backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(gameScreenFullPalGroenEnBlauw, sizeof(gameScreenFullPalGroenEnBlauw)));
            }
            else {
                backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(gameScreenFullPalGroen, sizeof(gameScreenFullPalGroen)));

            }

        }
        else {
            if (game->getSpeler()->getSpel3Gehaald()) {
                backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(gameScreenFullPalBlauw, sizeof(gameScreenFullPalBlauw)));
            }
            else {
                backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(gameScreenFullPalZwart, sizeof(gameScreenFullPalZwart)));
            }

        }

    }

    background = std::unique_ptr<Background>(new Background(2, gameScreenFullTiles, sizeof(gameScreenFullTiles), tijdelijk, sizeof(tijdelijk)));
    background->useMapScreenBlock(4);
    background2 = std::unique_ptr<Background>(new Background(1, gameScreenFullTiles, sizeof(gameScreenFullTiles), transparantAndRedMap, sizeof(transparantAndRedMap)));
    background2->useMapScreenBlock(21);
    

    TextStream::instance().setText(std::string("Score"), 1, 25);
    TextStream::instance().setText(std::string(std::to_string(game->getSpeler()->getScore())), 2, 25);
    TextStream::instance().setText(std::string("Moves"), 3, 25);
    TextStream::instance().setText(std::string(std::to_string(game->getSpeler()->getVakjesNogVerschuiven())), 4, 25);

    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    SpriteBuilder<Sprite> spriteBuilder;

    if (spriteKeuze == 0) {
        spook1Sprite = spriteBuilder
                .withData(wit_spook_1Tiles, sizeof(wit_spook_1Tiles))
                .withSize(SIZE_32_32)
                .withAnimated(6, 8)
                .withLocation(0, 0)
                .buildPtr();
    }
    else {
        spook1Sprite = spriteBuilder
                .withData(wit_spook_2Tiles, sizeof(wit_spook_2Tiles))
                .withSize(SIZE_32_32)
                .withAnimated(6, 8)
                .withLocation(0, 0)
                .buildPtr();
    }

    dobbelSteenSprite = spriteBuilder
            .withData(dobbelsteenTiles, sizeof(dobbelsteenTiles))
            .withSize(SIZE_32_32)
            .withAnimated(3, 6)
            .withLocation(200, 120)
            .buildPtr();

    steenRoodSprite = spriteBuilder
            .withData(red_stone_with_borderTiles, sizeof(red_stone_with_borderTiles))
            .withSize(SIZE_32_32)
            .withAnimated(2, 8)
            .withLocation(210, 50)
            .buildPtr();
    steenRoodSprite->stopAnimating();
    steenGroenSprite = spriteBuilder
            .withData(green_stone_with_borderTiles, sizeof(green_stone_with_borderTiles))
            .withSize(SIZE_32_32)
            .withAnimated(2, 8)
            .withLocation(210, 70)
            .buildPtr();
    steenGroenSprite->stopAnimating();
    steenBlauwSprite = spriteBuilder
            .withData(blue_stone_with_borderTiles, sizeof(blue_stone_with_borderTiles))
            .withSize(SIZE_32_32)
            .withAnimated(2, 8)
            .withLocation(210, 90)
            .buildPtr();
    steenBlauwSprite->stopAnimating();

    dobbelSteenSprite->stopAnimating();
    updatePosition();
    updateInformation();
    engine->getTimer()->start();

    engine->enqueueMusic(gameScreenMusic, sizeof(gameScreenMusic), 44100);

}

std::vector<Sprite *> GameScreen::sprites() {return {spook1Sprite.get(), dobbelSteenSprite.get(), steenRoodSprite.get(), steenGroenSprite.get(), steenBlauwSprite.get()};}

std::vector<Background *> GameScreen::backgrounds() {return {background.get(), background2.get()};}

void GameScreen::tick(u16 keys) {
    if (firstTick) {
        firstTick = false;
        lastKeys = keys;
        return;
    }
    if (aanHetGooien) {
        if (!(keys & KEY_START) && (lastKeys & KEY_START)) {

            dobbelSteenSprite->stopAnimating();
            game->getSpeler()->gooiDobbelsteen(dobbelSteenSprite->getCurrentFrame() + 1);

            aanHetGooien = false;
            updatePosition();

        }
    }
    else {
        if (!(keys & KEY_RIGHT) && (lastKeys & KEY_RIGHT)) {
            game->getSpeler()->beweegNaarRechts();
            updatePosition();
        } else if (!(keys & KEY_LEFT) && (lastKeys & KEY_LEFT)) {
            game->getSpeler()->beweegNaarLinks();
            updatePosition();
        } else if (!(keys & KEY_UP) && (lastKeys & KEY_UP)) {
            game->getSpeler()->beweegNaarBoven();
            updatePosition();
        } else if (!(keys & KEY_DOWN) && (lastKeys & KEY_DOWN)) {
            game->getSpeler()->beweegNaarOnder();
            updatePosition();
        } else if (!(keys & KEY_START) && (lastKeys & KEY_START)) {
            aanHetGooien = true;
            if (!game->getSpeler()->getAlGegooid()) {
                dobbelSteenSprite->animate();
            }
        }
    }
    if (aanHetSpringen and (game->getHuidigVakje() == 4 or game->getHuidigVakje() == 5)) {
        int seed = engine->getTimer()->getTotalMsecs();
        std::uniform_int_distribution<unsigned> u(1, 2);
        std::default_random_engine e(seed * seed); //anders kwam je denk ik te vaak op hetzelfde. Nog eens fatsoenlijk uitzoeken hoe dit zit.
        int random = u(e);

        engine->getTimer()->stop();
        engine->getTimer()->reset();
        engine->getTimer()->start();
        while (engine->getTimer()->getTotalMsecs() < 1000) {}

        if (game->getHuidigVakje() == 4) {
            if (random == 1) {game->getSpeler()->springNaarLinks();}
            else {game->getSpeler()->springNaarRechts();}
        }
        else {
            if (random == 1) {game->getSpeler()->springNaarBoven();}
            else {game->getSpeler()->springNaarOnder();}
        }
        updatePosition();
        aanHetSpringen = false;
    }
    else {
        if (game->getSpeler()->getAlGegooid() and game->getSpeler()->getVakjesNogVerschuiven() == 0) {
            switch(game->getHuidigVakje()) {
                case 1:
                    if (!engine->isTransitioning()) {
                        engine->transitionIntoScene(new Minigame1Screen(engine, game, spriteKeuze), new FadeOutScene(2));
                    }
                    break;
                case 2:
                    if (!engine->isTransitioning()) {
                        engine->transitionIntoScene(new Minigame2Screen(engine, game, spriteKeuze), new FadeOutScene(2));
                    }
                    break;
                case 3:
                    if (!engine->isTransitioning()) {
                        engine->transitionIntoScene(new Minigame3Screen(engine, game, spriteKeuze), new FadeOutScene(2));
                    }
                    break;
                case 4:
                case 5:
                    aanHetSpringen = true;
                    break;

                case 6:
                    if (game->getSpeler()->getSpel1Gehaald() and game->getSpeler()->getSpel2Gehaald() and game->getSpeler()->getSpel3Gehaald()) {
                        if (!engine->isTransitioning()) {
                            engine->transitionIntoScene(new EndScreen(engine, game->getSpeler()->getScore()), new FadeOutScene(2));
                        }
                    }
                    else {
                        game->getSpeler()->setAlGegooid(false);
                    }
                    break;
                case 7:
                    game->getSpeler()->setAlGegooid(false);
                    break;
            }
        }
    }
    lastKeys = keys;
}

void GameScreen::updatePosition() {
    int bgX = 0;
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
    spook1Sprite->moveTo(spX*32, spY*32);
    background->scroll(bgX * 32,bgY*32);
    TextStream::instance().setText(std::string(std::to_string(game->getSpeler()->getVakjesNogVerschuiven())), 4, 25);

}

void GameScreen::updateInformation() {

    TextStream::instance().setText(std::string(std::to_string(game->getSpeler()->getScore())), 2, 25);

    if (game->getSpeler()->getSpel1Gehaald()) {
        steenRoodSprite->animateToFrame(1);
    }
    if (game->getSpeler()->getSpel2Gehaald()) {
        steenGroenSprite->animateToFrame(1);
    }
    if (game->getSpeler()->getSpel3Gehaald()) {
        steenBlauwSprite->animateToFrame(1);
    }
}




