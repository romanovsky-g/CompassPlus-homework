#pragma once
#include <iostream>
#include <vector>
#include <Arrow.h>

using namespace std;

struct GameState {
public:
	int maxArrowAmount = 5;
	int currArrowAmount = 0;
	vector<SDL_Rect*> arrows;
};