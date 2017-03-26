#pragma once
#include "Map.h"
#include "Input.h"
#include "CoinManager.h"

class Player 
{
public:

	int playerX, playerY;
	int score;

	Player(Map mapa);
	~Player();
	void updatePlayer(Map mapa, Input::Key keyPressed, CoinManager coins);
	
};

