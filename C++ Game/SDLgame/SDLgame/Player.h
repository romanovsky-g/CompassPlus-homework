#pragma once
#include "Game.h"
#include "GameObject.h"


class Player : public GameObject {
public:
    Player(int initSpeed);
    ~Player();

    void update();
    void render();
private:
    int xvel = 0;
    int yvel = 0;
    int speed = 5;
};







/*
SDL_Event event;

    SDL_PollEvent(&event);

    switch (event.type) {
        // Look for a keypress
    case SDL_KEYDOWN:
        // Check the SDLKey values and move change the coords
        switch (event.key.keysym.sym) {
        case SDLK_a:
            xvel = -speed;
            break;
        case SDLK_d:
            xvel = speed;
            break;
        case SDLK_w:
            yvel = -speed;
            break;
        case SDLK_s:
            yvel = speed;
            break;
        default:
            break;
        }
        break;
    case SDL_KEYUP:
        switch (event.key.keysym.sym) {
        case SDLK_a:
            if (xvel < 0)
                xvel = 0;
            break;
        case SDLK_d:
            if (xvel > 0)
                xvel = 0;
            break;
        case SDLK_w:
            if (yvel < 0)
                yvel = 0;
            break;
        case SDLK_s:
            if (yvel > 0)
                yvel = 0;
            break;
        default:
            break;
        }
        break;

    default:
        break;
    }

    x += xvel;
    y += yvel;
*/