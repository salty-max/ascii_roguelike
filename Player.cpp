//
// Created by Maxime Blanc on 01/09/2021.
//

#include "Player.h"
#include <ctime>
#include <random>

void Player::init(WINDOW *win, int level, int health, int attack, int defense,
                  int experience) {
  _win = win;
  _level = level;
  _health = health;
  _attack = attack;
  _defense = defense;
  _experience = experience;
  _expToNextLevel = 50;
}

void Player::setPosition(int x, int y) {
  _x = x;
  _y = y;
}

void Player::getPosition(int &x, int &y) {
  x = _x;
  y = _y;
}

void Player::addXP(int value) {
  _experience += value;

  if (_experience >= _expToNextLevel) {
    _level++;
    _attack += 10;
    _defense += 5;
    _health += 10;
    _expToNextLevel += _expToNextLevel * 2;
    printw("You are now level %d\nAttack: %d  Defense: %d  Health: %d\n", _level, _attack, _defense, _health);
    getch();
  }
}

int Player::attack() {
  static std::default_random_engine randomEngine(time(nullptr));
  std::uniform_int_distribution<int> attackRoll(0, _attack);

  return attackRoll(randomEngine);
}

int Player::takeDamage(int attackValue) {
  attackValue -= _defense;

  if (attackValue > 0) {
    _health -= attackValue;

    if (_health <= 0) {
      return 1;
    }
  }

  return 0;
}
