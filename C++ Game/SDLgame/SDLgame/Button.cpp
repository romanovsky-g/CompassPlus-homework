#pragma once
#include "Button.h"

Button::Button(const char* texture, SDL_Renderer* rend, int buttonX, int buttonY, int buttonW, int buttonH, int texturePosX = 0, int texturePosY = 0) : GameObject(texture, rend, buttonX, buttonY) {
    x = buttonX;
    y = buttonY;

    srcRect.h = buttonH;
    srcRect.w = buttonW;
    srcRect.x = texturePosX;
    srcRect.y = texturePosY;
}

Button::~Button()
{}

bool Button::mouseHovering()
{
    int mouseX, mouseY = 0;
    SDL_GetMouseState(&mouseX, &mouseY);
    if ((mouseX > x) && (mouseX < x + w) &&
        (mouseY > y) && (mouseY < y + h))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Button::handle_event(SDL_Event* evt)
{
    switch (evt->type) {
        // Look for a keypress
    case SDL_MOUSEBUTTONDOWN:
        switch (evt->key.keysym.sym) {
        case SDL_BUTTON_LEFT:
            buttonPressed = true;
            break;

        default:
            break;
        }

        break;
    case SDL_KEYUP:
        switch (evt->key.keysym.sym) {
        case SDL_BUTTON_LEFT:
            buttonPressed = false;
            pressedOnce = true;
            break;

        default:
            break;
        }

        break;
    default:
        break;
    }
}

void Button::update()
{
    if (mouseHovering())
    {
        if (buttonPressed && pressedOnce)
        {
            //onClick();
        }
        pressedOnce = false;

    } else {/*do nothing*/ }

    destRect.x = x;
    destRect.y = y;
    destRect.w = srcRect.w;
    destRect.h = srcRect.h;
}

void Button::render()
{
    GameObject::render();
}