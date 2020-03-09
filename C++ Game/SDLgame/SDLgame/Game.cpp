#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include <vector>
using namespace std;

Player* player;
vector<GameObject*> enteties;
vector<GameObject*> listeners;

Game::Game()
{}
Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Ititialised successfully!" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) { std::cout << "Window created successfully!" << std::endl; }

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created successfully!" << std::endl;
		}

		isRunning = true;
	} else {
		isRunning = false;
	}

	player = new Player("assets/test.png", renderer, 0, 0, 7);

	enteties.push_back(player);
	listeners.push_back(player); 
}

void Game::handle_event(SDL_Event* evt)
{
	for (auto ent : listeners)
	{
		ent->handle_event(evt);
	}
}

void Game::update()
{
	for (auto ent : enteties)
	{
		ent->update();
	}
}

void Game::render()
{	
	SDL_RenderClear(renderer);

	for (auto ent : enteties)
	{
		ent->render();
	}

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game closed successfully." << std::endl;
}
