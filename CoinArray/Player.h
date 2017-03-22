#pragma once
#include "Map.h"

class Player
{
public:

	int playerX, playerY;
	int score;

	Player(Map mapa, int numRows, int numColumns);
	~Player();
	bool isCoin(Map mapa, int x, int y);
};

