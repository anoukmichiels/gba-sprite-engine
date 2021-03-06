//
// Created by michi on 17/07/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_ENDSCREEN_H
#define GBA_SPRITE_ENGINE_PROJECT_ENDSCREEN_H


#include <libgba-sprite-engine/scene.h>

class EndScreen : public Scene{
private:
    u16 lastKeys = 0;
    bool firstTick = true;
    std::unique_ptr<Background> background;
    std::unique_ptr<Sprite> ghostFamily1;
    std::unique_ptr<Sprite> ghostFamily2;
    std::unique_ptr<Sprite> ghostFamily3;
    std::unique_ptr<Sprite> ghostFamily4;
    std::unique_ptr<Sprite> pijl;


    int score;
public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    EndScreen(std::shared_ptr<GBAEngine> &engine, int score) : Scene(engine), score(score){}; //Kijken of ik hier &engine ofzo moet doen

    void load() override;
    void tick(u16 keys) override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_ENDSCREEN_H
