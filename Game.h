//
// Created by Maxime Blanc on 01/09/2021.
//

#pragma once

#include "Level.h"
#include "Player.h"
#include <ncurses.h>
#include <vector>

class Game {
public:
    Game(const char *levelFileName);
    void initWindow();
    void play();
    void movePlayer();
private:
    Player _player;
    Level _level;
	WINDOW *_win;
};