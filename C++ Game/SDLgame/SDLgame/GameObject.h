#pragma once
#include "Game.h"

class GameObject {

public:
	GameObject(const char* texture, SDL_Renderer* rend, int initX, int initY);
	~GameObject();

	void update();
	void render();

private:
	int x;
	int y;
	
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
};