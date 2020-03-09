#include "Player.h"

Player::Player(const char* texture, SDL_Renderer* rend, int initX, int initY, int initSpeed) : GameObject(texture, rend, initX, initY) {
	speed = initSpeed;
    x = initX;
    y = initY;
}

Player::~Player()
{}

void Player::handle_event(SDL_Event* evt)
{
    switch (evt->type) {
        // Look for a keypress
    case SDL_KEYDOWN:
        // Check the SDLKey values and move change the coords
        switch (evt->key.keysym.sym) {
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
        switch (evt->key.keysym.sym) {
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
}

void Player::update()
{
    GameObject::update();

    x += xvel;
    y += yvel;
}

void Player::render()
{
    GameObject::render();
}