//
// Created by Maxime Blanc on 01/09/2021.
//

#pragma once

#include "Enemy.h"
#include "Player.h"
#include <ncurses.h>
#include <string>
#include <vector>

class Level {
public:
  void init(WINDOW *win);
  void load(const char *fileName, Player &player);
  void print();
  void tryMovePlayer(char input, Player &player);
  void setTile(int x, int y, char ch);
  char getTile(int x, int y);

private:
  void processPlayerMove(Player &player, int destx, int desty);
  void battleEnemy(Player &player, int targetx, int targety);

private:
  std::vector<std::string> _levelData;
  std::vector<Enemy> _enemies;
  WINDOW *_win;
};