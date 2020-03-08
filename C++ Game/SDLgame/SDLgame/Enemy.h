#pragma once
#include "Game.h"
#include "GameObject.h"


class Enemy : public GameObject {
public:
    Enemy(const char* texture, SDL_Renderer* rend, int initX, int initY, SDL_Event gameEvent, int destinationX, int destinationY, int initSpeed);
    ~Enemy();

    void update();
    void render();

protected:
    int xvel = 0;
    int yvel = 0;

    int destinationX;
    int destinationY;
    int speed = 0;
};
