//
// Created by Maxime Blanc on 01/09/2021.
//

#pragma once

#include "Level.h"
#include "Player.h"
#include <vector>

class Game {
public:
    Game(const char *levelFileName);
    void play();
private:
    Player _player;
    Level _level;
};