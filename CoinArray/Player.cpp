#include "Player.h"
#include "Map.h"
#include "CoinManager.h"
#include <iostream>


Player::Player(Map mapa) :
	score (0)
{

	int auxRow, auxColumn;
	bool foundCoin = true;

	do {
		auxColumn = (rand() % mapa.numColumns);
		auxRow = (rand() % mapa.numRows);

		if (mapa.map[auxRow][auxColumn] != '$') foundCoin = false;


	} while (foundCoin == true);

	playerRow = auxRow;
	playerColumn = auxColumn;

	mapa.map[playerRow][playerColumn] = '@';

}


Player::~Player()
{
}

void Player::updatePlayer (Map mapa, Input::Key keyPressed, CoinManager *coins) {

	switch (keyPressed)
	{
	case Input::Key::W:
		if (playerRow > 0) {
			mapa.modifyMap(playerRow, playerColumn, '.');
			playerRow--;
			if (mapa.map[playerRow][playerColumn] == '$') {
				score++;
				coins->updateCoins(playerRow, playerColumn, mapa);
			}
			else mapa.modifyMap(playerRow, playerColumn, '@');
		}
		break;
	case Input::Key::A:
		if (playerColumn > 0) {
			mapa.modifyMap(playerRow, playerColumn, '.');
			playerColumn--;
			if (mapa.map[playerRow][playerColumn] == '$') {
				score++;
				coins->updateCoins(playerRow, playerColumn, mapa);
			}
			 else mapa.modifyMap(playerRow, playerColumn, '@');
		}
		break;
	case Input::Key::S:
		if (playerRow < mapa.numRows-1) {
			mapa.modifyMap(playerRow, playerColumn, '.');
			playerRow++;
			if (mapa.map[playerRow][playerColumn] == '$') {
				score++;
				coins->updateCoins(playerRow, playerColumn, mapa);
			}
			else mapa.modifyMap(playerRow, playerColumn, '@');
		}
		break;
	case Input::Key::D:
		if (playerColumn < mapa.numColumns-1) {
			mapa.modifyMap(playerRow, playerColumn, '.');
			playerColumn++;
			if (mapa.map[playerRow][playerColumn] == '$') {
				score++;
				coins->updateCoins(playerRow, playerColumn, mapa);
			}
			else mapa.modifyMap(playerRow, playerColumn, '@');
		}
		break;
	}
}

