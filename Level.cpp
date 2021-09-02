//
// Created by Maxime Blanc on 01/09/2021.
//

#include "Level.h"
#include <cstdio>
#include <fstream>

void Level::init(WINDOW *win) { _win = win; }

void Level::load(const char *fileName, Player &player) {
  std::ifstream file;
  file.open(fileName);

  if (file.fail()) {
    perror(fileName);
    getchar();
    exit(1);
  }

  std::string line;
  while (std::getline(file, line)) {
    _levelData.push_back(line);
  }

  file.close();

  char tile;
  for (int y = 0; y < _levelData.size(); y++) {
    for (int x = 0; x < _levelData[y].size(); x++) {
      tile = getTile(x, y);

      switch (tile) {
      case '@':
        player.setPosition(x, y);
        break;
      case 'S':
        _enemies.emplace_back("Snake", tile, 1, 10, 3, 1, 10);
        _enemies.back().setPosition(x, y);
        break;
      case 'g':
        _enemies.emplace_back("Goblin", tile, 2, 35, 5, 3, 50);
        _enemies.back().setPosition(x, y);
        break;
      default:
        break;
      }
    }
  }
}

void Level::print() {
  clear();
  for (int i = 0; i < _levelData.size(); i++) {
    printw("%s\n", _levelData[i].c_str());
    refresh();
  }
}

void Level::tryMovePlayer(char input, Player &player) {
  int px, py;
  player.getPosition(px, py);

  switch (input) {
  case 'w':
    processPlayerMove(player, px, py - 1);
    break;
  case 's':
    processPlayerMove(player, px, py + 1);
    break;
  case 'a':
    processPlayerMove(player, px - 1, py);
    break;
  case 'd':
    processPlayerMove(player, px + 1, py);
    break;
  default:
    break;
  }
}

void Level::setTile(int x, int y, char ch) { _levelData[y][x] = ch; }

char Level::getTile(int x, int y) { return _levelData[y][x]; }

void Level::processPlayerMove(Player &player, int destx, int desty) {
  int px, py;
  player.getPosition(px, py);
  char destTile = getTile(destx, desty);

  switch (destTile) {
  case '#':
    break;
  case '.':
    player.setPosition(destx, desty);
    setTile(px, py, destTile);
    setTile(destx, desty, '@');
    break;
  default:
    battleEnemy(player, destx, desty);
    break;
  }
}

void Level::battleEnemy(Player &player, int targetx, int targety) {
  int ex, ey;
  int px, py;
  int attackRoll;
  int attackResult;

  player.getPosition(px, py);

  for (int i = 0; i < _enemies.size(); i++) {
    _enemies[i].getPosition(ex, ey);
    std::string enemyName = _enemies[i].getName();
    if (ex == targetx && ey == targety) {
      // Player turn
      attackRoll = player.attack();
      attackResult = _enemies[i].takeDamage(attackRoll);
      printw("Player attacked %s with a roll of %d\n", enemyName.c_str(), attackRoll);
      getch();

      if (attackResult > 0) {
        setTile(targetx, targety, '.');
        printw("%s died!\n", enemyName.c_str());
        player.addXP(attackResult);
        getch();

        return;
      }

      // Enemy turn
      attackRoll = _enemies[i].attack();
      attackResult = player.takeDamage(attackRoll);
      printw("%s attacked player with a roll of %d\n", enemyName.c_str(), attackRoll);
      getch();

      if (attackResult > 0) {
        setTile(px, py, 'X');
        printw("You died!\n");
        endwin();
        exit(1);
      }
    }
  }
}
