#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Batch.hpp"

class Texture{
public:
	Batch* batch;

	SDL_Texture* texture;


	Texture(Batch* batch, const char* path);
	
	~Texture();

	void draw(Batch* batch);


	void setPosition(Vector2 pos);
	void setPosition(int X, int Y);
	Vector2 getPosition();

	
	void setSize(int X, int Y);
	Vector2 getSize();

	void dispose();

	

private:
	Vector2 position;
	Vector2 size;

	void load(const char* path);
};

