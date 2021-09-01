//
// Created by Maxime Blanc on 01/09/2021.
//

#include "Player.h"

void Player::init(int level, int health, int attack, int defense, int experience) {
    _level = level;
    _health = health;
    _attack = attack;
    _defense = defense;
    _experience = experience;
}

void Player::setPosition(int x, int y) {
    _x = x;
    _y = y;
}

void Player::getPosition(int &x, int &y) {
    x = _x;
    y = _y;
}
