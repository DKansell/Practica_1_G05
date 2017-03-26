#pragma once
#include "Map.h"
#include "Input.h"

class Player 
{
	
public:
	int playerRow, playerColumn;
	int score;

	Player(Map mapa);
	~Player();
	void updatePlayer(Map mapa, Input::Key keyPressed, CoinManager *coins);
};

