//
// Created by Maxime Blanc on 01/09/2021.
//

#pragma once


class Player {
public:
    void init(int level, int health, int attack, int defense, int experience);
    void setPosition(int x, int y);
    void getPosition(int &x, int &y);

private:
    // Properties
    int _level;
    int _health;
    int _attack;
    int _defense;
    int _experience;

    // Position
    int _x;
    int _y;
};