#include "Enemy.h"

Enemy::Enemy(const char* texture, SDL_Renderer* rend, int initX, int initY, SDL_Event gameEvent, int destinationX, int destinationY, int initSpeed) : GameObject(texture, rend, initX, initY, gameEvent) {
    x = initX;
    y = initY;
    speed = initSpeed;
}