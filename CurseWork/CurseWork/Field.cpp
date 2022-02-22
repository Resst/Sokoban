#include "Field.hpp"

Field::Field(Game* GAME): game(GAME)
{
	empty = new Texture(game->batch, "empty.png");
	solid = new Texture(game->batch, "solid.png");
	place = new Texture(game->batch, "place.png");
	empty->setSize(TILE, TILE);
	solid->setSize(TILE, TILE);
	place->setSize(TILE, TILE);

	initLevel();
	initBoxes();
}

void Field::draw(Batch* batch)
{
	//drawing level
	for (int i = 0; i < gameField.size(); i++) {
		for (int j = 0; j < gameField[i].size(); j++) {
			switch (gameField[i][j]) {
			case 0:
				empty->setPosition(j * TILE, i * TILE);
				empty->draw(batch);
				break;
			case 1:
				solid->setPosition(j * TILE, i * TILE);
				solid->draw(batch);
				break;
			case 2:
				place->setPosition(j * TILE, i * TILE);
				place->draw(batch);
				break;
			}
		}
	}

	//drawing boxes
	for (int i = 0; i < boxes.size(); i++) {
		boxes.at(i).draw(batch);
	}
}


bool Field::finished()
{
	for (int i = 0; i < boxes.size(); i++)
		if (!boxes.at(i).completed())
			return false;
	return true;
}

void Field::initLevel()
{
	gameField.push_back(std::vector<int>());
	for (int i = 0; i < 15; i++) {
		gameField.push_back(std::vector<int>());
	}
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++)
			gameField.at(i).push_back(0);
	}
	for (int i = 0; i < 15; i++) {
		gameField.at(0).at(i) = 1;
		gameField.at(14).at(i) = 1;
		gameField.at(i).at(0) = 1;
		gameField.at(i).at(14) = 1;
	}

	gameField[3][2] = 2;
	gameField[3][3] = 2;
	gameField[3][4] = 2;
	gameField[3][5] = 2;
}

void Field::initBoxes()
{
	boxes.push_back(Box(2, 2, game));
	boxes.push_back(Box(3, 2, game));
	boxes.push_back(Box(4, 2, game));
	boxes.push_back(Box(5, 2, game));
}

void Field::dispose()
{
	delete empty;
	delete solid;
	delete place;
	for (int i = 0; i < boxes.size(); i++)
		boxes[i].dispose();
}

