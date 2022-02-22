#pragma once
#include "Utilities.cpp"
#include <SDL.h>

class Batch
{
public:

	SDL_Renderer* renderer;

	Batch(SDL_Window* window, int index, Uint32 flags);

	~Batch();

	void draw(SDL_Texture* texture, const SDL_Rect* srect, SDL_Rect* dstrect);

	void clear();	//clear screen
	void present();	//show on screen

	void translate(int x, int y);
	void setPosition(int x, int y);
	int getX();
	int getY();
	
	int getWidth();
	int getHeight();

	SDL_Texture* loadTexture();

	void dispose();

private:
	Vector2 position{0, 0};
	Vector2 size{ 0,0 };

};

