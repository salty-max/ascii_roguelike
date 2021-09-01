//
// Created by Maxime Blanc on 01/09/2021.
//

#pragma once

#include <vector>
#include <string>

class Level {
public:
    void load(std::string fileName);
    void print();
private:
    std::vector<std::string> _levelData;
};