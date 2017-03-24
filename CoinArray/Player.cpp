#include "Player.h"
#include "Map.h"
#include <iostream>


Player::Player(Map mapa) 
{

	int auxX, auxY;
	bool foundCoin = true;

	do {
		auxX = (rand() % mapa.numRows);
		auxY = (rand() % mapa.numColumns);

		if (mapa.map[auxX][auxY] != '$') foundCoin = false;


	} while (foundCoin == true);

	playerX = auxX;
	playerY = auxY;

	mapa.map[playerX][playerY] = '@';

}


Player::~Player()
{
}

