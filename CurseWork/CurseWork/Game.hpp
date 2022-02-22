#pragma once
#include <SDL.h>
#include <string>
#include "Texture.hpp"
#include "Object.hpp"
#include "Field.hpp"

#define WIDTH 800
#define HEIGHT 600
#define TILE 100

class Box;
class Player;
class Field;

class Game
{
public:
	const std::string title = "A GAME";

	Batch* batch;

	Player* player;
	Field* field;

	Game();

	bool init();	//initialization

	void start();
	void draw();	//drawing textures
	void update();	//called on each iteration
	void handle();

	void quit();
	void dispose();	//memory cleaner
	

private:
	bool run;		
	SDL_Window* window;



};

