//
// Created by michi on 11/08/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_MINIGAME2SCREEN_H
#define GBA_SPRITE_ENGINE_PROJECT_MINIGAME2SCREEN_H


#include <memory>
#include "MinigameScreen.h"

class Minigame2Screen : public  MinigameScreen{

public:
    Minigame2Screen(std::shared_ptr<GBAEngine> engine, std::shared_ptr<Game> gamepje, int sprite);
    void load() override;
    void setGehaald() override;
    void setBegintekst() override;
    void setEindtekst() override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_MINIGAME2SCREEN_H
