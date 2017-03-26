#include "Player.h"
#include "Map.h"
#include <iostream>


Player::Player(Map mapa) :
	score (0)
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

void Player::updatePlayer (Map mapa, Input::Key keyPressed, CoinManager coins) {

	switch (keyPressed)
	{
	case Input::Key::W:
		if (playerY > 0) {
			mapa.modifyMap(playerX, playerY, '.');
			playerY--;
			if (mapa.map[playerX][playerY] == '$') {
				score++;
				coins.updateCoins(playerX, playerY, mapa);
			}
			mapa.modifyMap(playerX, playerY, '@');
		}
		break;
	case Input::Key::A:
		if (playerX > 0) {
			mapa.modifyMap(playerX, playerY, '.');
			playerX--;
			if (mapa.map[playerX][playerY] == '$') {
				score++;
				coins.updateCoins(playerX, playerY, mapa);
			}
			mapa.modifyMap(playerX, playerY, '@');
		}
		break;
	case Input::Key::S:
		if (playerY < mapa.numRows) {
			mapa.modifyMap(playerX, playerY, '.');
			playerY++;
			if (mapa.map[playerX][playerY] == '$') {
				score++;
				coins.updateCoins(playerX, playerY, mapa);
			}
			mapa.modifyMap(playerX, playerY, '@');
		}
		break;
	case Input::Key::D:
		if (playerX < mapa.numRows) {
			mapa.modifyMap(playerX, playerY, '.');
			playerX++;
			if (mapa.map[playerX][playerY] == '$') {
				score++;
				coins.updateCoins(playerX, playerY, mapa);
			}
			mapa.modifyMap(playerX, playerY, '@');
		}
		break;
	}
}