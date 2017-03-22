#include "Player.h"
#include <iostream>



Player::Player(Map mapa, int numRows, int numColumns) 
{
	int auxX, auxY;
	bool foundCoin = true;

	do {
		auxX = (rand() % numRows);
		auxY = (rand() % numColumns);

		if (mapa[auxX][auxY] == '$') foundCoin = true;
		else foundCoin = false;

		//bool foundCoin = Player::isCoin(mapa, auxX, auxY);

	} while (foundCoin = !false);

	playerX = auxX;
	playerY = auxY;

}


Player::~Player()
{
}

bool Player::isCoin(Map mapa, int auxX, int auxY) {

	mapa[auxX][auxY] == '$';
}