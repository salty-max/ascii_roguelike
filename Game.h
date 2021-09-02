//
// Created by Maxime Blanc on 01/09/2021.
//

#pragma once

#include "Enemy.h"
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
  WINDOW *_win;
  Player _player;
  Level _level;
};