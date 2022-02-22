#include "Game.hpp"

Game::Game()
{
	init();
}

bool Game::init()
{
	run = true;
	window = SDL_CreateWindow(title.c_str(), 100, 100, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	batch = new Batch(window, -1, 0);
	field = new Field(this);
	
	player = new Player(1, 1, this);
	return true;
}

void Game::update()
{
	player->update();

	batch->setPosition(player->position.x * TILE + TILE / 2 - batch->getWidth() / 2, player->position.y * TILE + TILE / 2 - batch->getHeight() / 2);

	draw();

	if (field->finished())
		quit();
}

void Game::start()
{
	//main loop
	while (run)
	{
		handle();
		update();
	}

	dispose();
}

void Game::draw()
{
	batch->clear();

	field->draw(batch);
	player->draw(batch);

	batch->present();

}


void Game::handle()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		switch (e.type)
		{
			case SDL_QUIT:
			{
				quit();
				continue;
			}
			case SDL_KEYDOWN: 
			{
				if (player->handleInput(e.key.keysym.sym))
					continue;
			}

		}
	}
}

void Game::quit()
{
	run = false;
}

void Game::dispose()
{
	delete player;
	delete batch;
	field->dispose();
	delete field;
	SDL_DestroyWindow(window);
}
