//
// Created by Maxime Blanc on 01/09/2021.
//

#include "Game.h"
#include <fstream>

Game::Game(const char *levelFileName) {
    _level.load(levelFileName);
}

void Game::play() {
    _level.print();
}
