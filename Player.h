//
// Created by Maxime Blanc on 01/09/2021.
//

#pragma once

#include <ncurses.h>

class Player {
public:
  void init(WINDOW *win, int level, int health, int attack, int defense,
            int experience);
  void setPosition(int x, int y);
  void getPosition(int &x, int &y);
  void addXP(int value);

  int attack();
  int takeDamage(int attackValue);

private:
  WINDOW *_win;

  // Properties
  int _level;
  int _health;
  int _attack;
  int _defense;
  int _experience;
  int _expToNextLevel;

  // Position
  int _x;
  int _y;
};