//
// Created by michi on 14/04/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_SPELER_H
#define GBA_SPRITE_ENGINE_PROJECT_SPELER_H


#include <ctime>
#include <libgba-sprite-engine/timer.h>

class Speler {
private:
    int score;
    int posX;
    int posY;
    int vakjesNogVerschuiven;
    bool alGegooid;

    bool magNaarLinks;
    bool magNaarRechts;
    bool magNaarBoven;
    bool magNaarOnder;

    bool spel1Gehaald = false;
    bool spel2Gehaald = false;
    bool spel3Gehaald = false;


public:
    Speler();
    int getScore();
    void setScore(int extraScore);
    int getPosX();
    int getPosY();
    void beweegNaarRechts();
    void beweegNaarLinks();
    void beweegNaarOnder();
    void beweegNaarBoven();
    void springNaarRechts();
    void springNaarLinks();
    void springNaarOnder();
    void springNaarBoven();

    void setAlGegooid(bool gegooid);
    bool getAlGegooid();
    void gooiDobbelsteen(int ogen);
    int getVakjesNogVerschuiven();

    bool getSpel1Gehaald();
    bool getSpel2Gehaald();
    bool getSpel3Gehaald();

    void setSpel1Gehaald(bool gehaald);
    void setSpel2Gehaald(bool gehaald);
    void setSpel3Gehaald(bool gehaald);

};


#endif //GBA_SPRITE_ENGINE_PROJECT_SPELER_H
