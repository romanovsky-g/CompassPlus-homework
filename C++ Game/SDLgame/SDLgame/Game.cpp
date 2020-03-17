#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

#include "Block.h"
#include "Ground.h"
#include "Wall.h"
#include "FinishBlock.h"
#include "Button.h"
#include "GameState.h"

#include <vector>
#include "nlohmann/json.hpp"
#include <fstream>

using json = nlohmann::json;
using namespace std;

GameState gameState;

vector<GameObject*> enteties;
vector<GameObject*> listeners;

const char* tileTexPath = "assets/tiles.png";

Game::Game()
{}
Game::~Game()
{}

void SayHi()
{
	printf("Hello!");
}

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

	// Loading Map

	json levelFile;
	ifstream file("level/classic.json");
	file >> levelFile;

	int blockY = 0;


	for (auto blockRow : levelFile["1"])
	{
		for (size_t blockX = 0; blockX < 10; blockX++)
		{
			if (blockRow[blockX] == 0)
			{
				Ground* newGroundBlock = new Ground(tileTexPath, renderer, blockX, blockY, &gameState);

				enteties.push_back(newGroundBlock);
				listeners.push_back(newGroundBlock);
			}
			else if (blockRow[blockX] == 1) {
				Wall* newWallBlock = new Wall(tileTexPath, renderer, blockX, blockY);

				enteties.push_back(newWallBlock);
			}
			else if (blockRow[blockX] == 2) {
				FinishBlock* finishBlock = new FinishBlock(tileTexPath, renderer, blockX, blockY);

				enteties.push_back(finishBlock);
			}
			else if (blockRow[blockX] == 3) {
				Ground* spawnBlock = new Ground(tileTexPath, renderer, blockX, blockY, &gameState, true);

				enteties.push_back(spawnBlock);
				listeners.push_back(spawnBlock);
			}
			else
			{
				Block* errBlock = new Block(tileTexPath, renderer, blockX, blockY, 95, 0);

				enteties.push_back(errBlock);
			}

			cout << blockRow[blockX];
		}
		cout << endl;
		blockY++;
	}

	file.close();

	
	/*for (auto ent : enteties)
	{
		ent->offset(0, 44);
	}*/

	//Button* playButton = new Button("assets/ui.png", renderer, 0, 0, 112, 44, 0, 0);
	//playButton->onClick = SayHi;

	//enteties.push_back(playButton);
	//listeners.push_back(playButton);
	
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
	SDL_SetRenderDrawColor(renderer, 41, 41, 41, 255);
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
