#pragma once
#include "Game.hpp"
#include <vector>
#include <map>
#include <iostream>
class Game;
class Box;
class Field
{
public:

	Game* game;
	std::vector<Box> boxes;

	std::vector<std::vector<int>> gameField;

	Texture* empty;
	Texture* solid;
	Texture* place;

	Field(Game* GAME);


	void draw(Batch* batch);

	bool finished();

	void initLevel();

	void initBoxes();

	void dispose();
};

