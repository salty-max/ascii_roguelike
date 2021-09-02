#include "Game.h"

int main() {
  Game game(
      "/Users/max/Developer/cpp/ascii_roguelike/cmake-build-debug/level1.txt");
  game.initWindow();
  game.play();
  return 0;
}
