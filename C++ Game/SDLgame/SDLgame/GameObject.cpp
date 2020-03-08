#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texture, SDL_Renderer* rend, int initX, int initY, SDL_Event gameEvent)
{
	event = gameEvent;
	renderer = rend;
	objTexture = TextureManager::LoadTexture(texture, rend);

	x = initX;
	y = initY;
}

void GameObject::update()
{
	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = x;
	destRect.y = y;
	destRect.w = srcRect.w*2;
	destRect.h = srcRect.h*2;
}

void GameObject::render()
{
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}