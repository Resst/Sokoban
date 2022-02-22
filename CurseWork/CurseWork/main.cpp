#include <iostream>
#include <SDL.h>
#include "Game.hpp"

int main(int argc, char* args[]) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "SDL init error!\n";
		return -1;
	}

	Game* game = new Game();
	game->start();

	delete game;

	return 0;
}