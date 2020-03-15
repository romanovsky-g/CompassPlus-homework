#pragma once
#include "Game.h"
#include "GameObject.h"


class Button : public GameObject {
public:
    Button(const char* texture, SDL_Renderer* rend, int blockX, int blockY, int buttonW, int buttonH, int texturePosX, int texturePosY);
    ~Button();

    void handle_event(SDL_Event* evt);
    void update();
    void render();

private:
    bool pressedOnce = true;
    bool buttonPressed = false;

    int w = 0;
    int h = 0;
    bool mouseHovering();
};
