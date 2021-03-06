//
// Created by michi on 14/04/2020.
//
#include <algorithm>
#include "Speler.h"
#include <ctime>
#include <random>
#include <iostream>
#include <libgba-sprite-engine/gba_engine.h>

Speler::Speler() {
    score = 0;
    posX = 3;
    posY = 3;
    vakjesNogVerschuiven = 0;
    alGegooid = false;
    magNaarRechts = true;
    magNaarLinks = true;
    magNaarBoven = true;
    magNaarOnder = true;
}

int Speler::getScore() {
    return score;
}

void Speler::setScore(int extraScore) {
    score += extraScore;
}

void Speler::beweegNaarRechts() {
    if ((posY == 0 or posY == 3 or posY == 6) and posX != 6 and vakjesNogVerschuiven != 0 and magNaarRechts) {
        posX++;
        vakjesNogVerschuiven--;
        magNaarLinks = false;
        magNaarBoven = true;
        magNaarOnder = true;
    }
}

void Speler::beweegNaarLinks() {
    if ((posY == 0 or posY == 3 or posY == 6) and posX != 0 and vakjesNogVerschuiven != 0 and magNaarLinks) {
        posX--;
        vakjesNogVerschuiven--;
        magNaarRechts = false;
        magNaarBoven = true;
        magNaarOnder = true;
    }
}

void Speler::beweegNaarOnder() {
    if ((posX == 0 or posX == 3 or posX == 6) and posY != 6 and vakjesNogVerschuiven != 0 and magNaarOnder) {
        posY++;
        vakjesNogVerschuiven--;
        magNaarBoven = false;
        magNaarRechts = true;
        magNaarLinks = true;
    }
}

void Speler::beweegNaarBoven() {
    if ((posX == 0 or posX == 3 or posX == 6) and posY != 0 and vakjesNogVerschuiven != 0 and magNaarBoven) {
        posY--;
        vakjesNogVerschuiven--;
        magNaarOnder = false;
        magNaarRechts = true;
        magNaarLinks = true;
    }
}

int Speler::getPosX() {
    return posX;
}

int Speler::getPosY() {
    return posY;
}

void Speler::setAlGegooid(bool gegooid) {
    alGegooid = gegooid;
}

bool Speler::getAlGegooid() {
    return alGegooid;
}

void Speler::gooiDobbelsteen(int ogen) {
    if (!alGegooid or alGegooid) {


        vakjesNogVerschuiven = ogen;

        alGegooid = true;
        magNaarBoven = true;
        magNaarOnder = true;
        magNaarLinks = true;
        magNaarRechts = true;
    }

}

int Speler::getVakjesNogVerschuiven() {
    return vakjesNogVerschuiven;
}

void Speler::springNaarRechts() {
    posX = posX + 3;
}

void Speler::springNaarLinks() {
    posX = posX - 3;
}

void Speler::springNaarOnder() {
    posY = posY + 3;
}

void Speler::springNaarBoven() {
    posY = posY - 3;
}

bool Speler::getSpel1Gehaald() {
    return spel1Gehaald;
}

bool Speler::getSpel2Gehaald() {
    return spel2Gehaald;
}

bool Speler::getSpel3Gehaald() {
    return spel3Gehaald;
}

void Speler::setSpel1Gehaald(bool gehaald) {
    spel1Gehaald = gehaald;
}

void Speler::setSpel2Gehaald(bool gehaald) {
    spel2Gehaald = gehaald;
}

void Speler::setSpel3Gehaald(bool gehaald) {
    spel3Gehaald = gehaald;
}



