#include "Texture.hpp"

Texture::Texture(Batch* batch, const char* path)
{
	this->batch = batch;
	load(path);
}

Texture::~Texture()
{
	dispose();
}

void Texture::load(const char* path)
{
	texture = SDL_CreateTextureFromSurface(batch->renderer, IMG_Load(path));
}

void Texture::draw(Batch* batch)
{
	SDL_Rect rect;
	rect.x = position.x;
	rect.y = position.y;
	rect.w = size.x;
	rect.h = size.y;
	batch->draw(texture, NULL, &rect);
}

void Texture::setPosition(Vector2 pos)
{
	position.x = pos.x;
	position.y = pos.y;
}

void Texture::setPosition(int X, int Y)
{
	position.x = X;
	position.y = Y;
}

Vector2 Texture::getPosition()
{
	return position;
}

void Texture::setSize(int X, int Y)
{
	size.x = X;
	size.y = Y;
}

Vector2 Texture::getSize()
{
	return size;
}

void Texture::dispose()
{
	SDL_DestroyTexture(texture);
}
