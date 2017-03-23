#include "Player.h"
#include "Map.h"
#include <iostream>


Player::Player() 
{

	int auxX, auxY;
	bool foundCoin = true;

	do {
		auxX = (rand() % numRows);
		auxY = (rand() % numColumns);

		if (map[auxX][auxY] == '$') foundCoin = true;
		else foundCoin = false;


	} while (foundCoin = !false);

	playerX = auxX;
	playerY = auxY;

}


Player::~Player()
{
}

