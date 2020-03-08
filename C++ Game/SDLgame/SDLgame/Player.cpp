#include "Player.h"

Player::Player(const char* texture, SDL_Renderer* rend, int initX, int initY, SDL_Event gameEvent, int initSpeed) : GameObject(texture, rend, initX, initY, gameEvent) {
	speed = initSpeed;
    x = initX;
    y = initY;
}

void Player::update()
{
    GameObject::update();

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
        
        default:
            break;
        }
        break;

    default:
        break;
    }

    x += xvel;
    y += yvel;
}

void Player::render()
{
    GameObject::render();
}