#pragma once
#include "Game.hpp"

class Game;

class Object
{
public:
	Game* game;

	Vector2 position{};

	Texture* texture;

	Object(const int x, const int y, const char* path, Game* GAME);

	bool move(int x, int y);
	bool canMove(int x, int y);

	void update();
	void draw(Batch* batch);

	void dispose();

};

class Player : public Object
{
public:

	Player(int x, int y, Game* Game);

	bool handleInput(SDL_Keycode keyCode);

	bool canMove(int x, int y);

	bool move(int x, int y);
};

class Box : public Object 
{
public:

	Box(int x, int y, Game* GAME);

	bool completed();

	bool canMove(int x, int y);

	bool move(int x, int y);
};

