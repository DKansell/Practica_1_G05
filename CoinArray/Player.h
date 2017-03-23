#pragma once
#include "Map.h"

class Player : public Map
{
public:

	int playerX, playerY;
	int score;

	Player();
	~Player();
	//bool isCoin(Map mapa, int x, int y);
};

