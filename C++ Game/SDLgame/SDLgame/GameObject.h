#pragma once
#include "Game.h"

class GameObject {

public:
	GameObject(const char* texture, SDL_Renderer* rend, int initX, int initY, SDL_Event gameEvent);
	~GameObject();

	virtual void update();
	void render();
	SDL_Event event;

protected:
	int x;
	int y;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
};