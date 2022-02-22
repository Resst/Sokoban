#include "Batch.hpp"


Batch::Batch(SDL_Window* window, int index = -1, Uint32 flags = 0) {
	renderer = SDL_CreateRenderer(window, index, flags);
    SDL_GetWindowSize(window, &size.x, &size.y);
}

Batch::~Batch()
{
    dispose();
}

void Batch::draw(SDL_Texture* texture, const SDL_Rect* srect, SDL_Rect* dstrect)
{
    dstrect->x -= position.x;
    dstrect->y -= position.y;
    SDL_RenderCopy(renderer, texture, srect, dstrect);
}

void Batch::clear()
{
    SDL_RenderClear(renderer);
}

void Batch::present()
{
    SDL_RenderPresent(renderer);
}

void Batch::translate(int x, int y)
{
    position.translate(x, y);
}

void Batch::setPosition(int x, int y)
{
    position.set(x, y);
}

int Batch::getX()
{
    return position.x;
}

int Batch::getY()
{
    return position.y;
}

int Batch::getWidth()
{
    return size.x;
}

int Batch::getHeight()
{
    return size.y;
}

SDL_Texture* Batch::loadTexture()
{
    return nullptr;
}

void Batch::dispose()
{
    SDL_DestroyRenderer(renderer);
}
