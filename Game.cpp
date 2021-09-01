//
// Created by Maxime Blanc on 01/09/2021.
//

#include "Game.h"
#include <ncurses.h>

Game::Game(const char *levelFileName) {
    _player.init(1, 100, 10, 10, 0);
	_level.init(_win);
    _level.load(levelFileName, _player);
}

void Game::initWindow() {
	// Init ncurses
	initscr();
	noecho();
	cbreak();

	// Get screen size
	int xMax, yMax;
	getmaxyx(stdscr, yMax, xMax);

	// Create window
	_win = newwin(20, 50, 0, 0);
	refresh();
	wrefresh(_win);
}

void Game::play() {
    bool playing = true;

	while (playing) {
		_level.print();
		movePlayer();
	}
}

void Game::movePlayer() {
    char ch;
    ch = getch();
	_level.tryMovePlayer(ch, _player);
	refresh();
}
