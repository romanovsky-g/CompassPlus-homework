#pragma once
#include "Game.h"
#include "GameObject.h"
#include "GameState.h"


class Player : public GameObject {
public:
    Player(const char* texture, SDL_Renderer* rend, int initX, int initY, int initSpeed, GameState* gameState);
    ~Player();

    void handle_event(SDL_Event* evt);
    void update();
    void render();

private:
    int xvel = 0;
    int yvel = 0;
    int speed = 0;
    GameState* gameState;
};
