#include "Object.hpp"

Object::Object(const int x, const int y, const char* path, Game* GAME): game(GAME)
{
	position.set(x, y);
	texture = new Texture(game->batch, path);
	texture->setSize(TILE, TILE);
	texture->setPosition(x * TILE, y * TILE);
}

bool Object::move(int x, int y)
{
	bool can = canMove(x, y);
	if (can) {
		position.translate(x, y);
		texture->setPosition(position.x * TILE, position.y * TILE);
	}
	return can;
}

bool Object::canMove(int x, int y)
{
	bool can;
	try {
		can = game->field->gameField.at(position.y + y).at(position.x + x) != 1;
	}
	catch (const std::out_of_range& e) {
		can = false;
	}
	return can;
}

void Object::update()
{

}

void Object::draw(Batch* batch)
{
	texture->draw(batch);
}

void Object::dispose()
{
	texture->dispose();
}



Player::Player(int x, int y, Game* GAME) :Object(x, y, "player.png", GAME) {}



bool Player::handleInput(SDL_Keycode keyCode)
{
	switch (keyCode) {
	case SDLK_LEFT:
	case SDLK_a:
		move(-1, 0);
		break;
	case SDLK_RIGHT:
	case SDLK_d:
		move(1, 0);
		break;
	case SDLK_UP:
	case SDLK_w:
		move(0, -1);
		break;
	case SDLK_DOWN:
	case SDLK_s:
		move(0, 1);
		break;
	default:
		return false;
	}
	return true;
}

bool Player::canMove(int x, int y)
{
	bool can = Object::canMove(x, y);

	for (int i = 0; i < game->field->boxes.size(); i++)
		if (can && game->field->boxes.at(i).position.equal(position.x + x, position.y + y)) {
			can = game->field->boxes.at(i).move(x, y);
		}

	return can;
}

bool Player::move(int x, int y)
{
	bool can = canMove(x, y);
	if (can) {
		position.translate(x, y);
		texture->setPosition(position.x * TILE, position.y * TILE);
	}
	return can;
}

Box::Box(int x, int y, Game* GAME) : Object(x, y, "box.png", GAME)
{}

bool Box::completed()
{
	return game->field->gameField[position.y][position.x] == 2;
}

bool Box::canMove(int x, int y)
{
	bool can = Object::canMove(x, y);
	if (can)
		for (int i = 0; i < game->field->boxes.size(); i++)
			if (game->field->boxes.at(i).position.equal(position.x + x, position.y + y)) {
				return false;
			}

	return can;
}

bool Box::move(int x, int y)
{
	bool can = canMove(x, y);
	if (can) {
		position.translate(x, y);
		texture->setPosition(position.x * TILE, position.y * TILE);
	}
	return can;
}
