#pragma once
#include "Game.h"
#include "GameObject.h"
#include "Block.h"

class FinishBlock : public Block {
public:
    FinishBlock(const char* texture, SDL_Renderer* rend, int blockX, int blockY);
    ~FinishBlock();

    void handle_event(SDL_Event* evt);
    void update();
    void render();
};

