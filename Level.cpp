//
// Created by Maxime Blanc on 01/09/2021.
//

#include "Level.h"
#include <fstream>
#include <cstdio>
#include <iostream>

void Level::load(std::string fileName) {
    std::ifstream file;
    file.open(fileName);

    if (file.fail()) {
        perror(fileName.c_str());
        getchar();
        exit(1);
    }

    std::string line;
    while(std::getline(file, line)) {
        _levelData.push_back(line);
    }

    file.close();
}

void Level::print() {
    for (int i = 0; i < _levelData.size(); i++) {
        printf("%s\n", _levelData[i].c_str());
    }
    printf("\n");
}
