//
// Created by Maxime Blanc on 02/09/2021.
//

#include "Enemy.h"
#include <ctime>
#include <random>

Enemy::Enemy(std::string name, char tile, int level, int health, int attack,
             int defense, int xpValue) {
  _name = name;
  _tile = tile;
  _level = level;
  _health = health;
  _attack = attack;
  _defense = defense;
  _xpValue = xpValue;
}

void Enemy::setPosition(int x, int y) {
  _x = x;
  _y = y;
}

void Enemy::getPosition(int &x, int &y) {
  x = _x;
  y = _y;
}

std::string Enemy::getName() { return _name; }

int Enemy::attack() {
  static std::default_random_engine randomEngine(time(nullptr));
  std::uniform_int_distribution<int> attackRoll(0, _attack);

  return attackRoll(randomEngine);
}

int Enemy::takeDamage(int attackValue) {
  attackValue -= _defense;

  if (attackValue > 0) {
    _health -= attackValue;

    if (_health <= 0) {
      return _xpValue;
    }
  }

  return 0;
}
