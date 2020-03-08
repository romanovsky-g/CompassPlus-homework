#pragma once
#include "Game.h"
#include "GameObject.h"


class Player : public GameObject {
public:
    Player(const char* texture, SDL_Renderer* rend, int initX, int initY, SDL_Event gameEvent, int initSpeed);
    ~Player();

    void update();
    void render();

private:
    int xvel = 0;
    int yvel = 0;
    int speed = 0;
};
