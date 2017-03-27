#include "Player.h"
#include "Map.h"
#include "CoinManager.h"
#include <iostream>


Player::Player(Map mapa) :
	score (0) //Inicializamos la puntuación a 0.
{
	int auxRow, auxColumn; ///Variables auxiliares para el bucle de posicionamiento inicial.
	bool foundCoin = true; 

	//Determinamos posición inicial del jugador al azar sin que coincida con una moneda.
	do {
		auxColumn = (rand() % mapa.numColumns);
		auxRow = (rand() % mapa.numRows);

		if (mapa.map[auxRow][auxColumn] != '$') foundCoin = false;


	} while (foundCoin == true);

	//Asigna los valores auxiliares a los atributos del jugador.
	playerRow = auxRow;
	playerColumn = auxColumn;
	//Dibujamos al jugador en el mapa.
	mapa.map[playerRow][playerColumn] = '@';
}


Player::~Player()
{
}

void Player::updatePlayer (Map mapa, Input::Key keyPressed, CoinManager *coins) 
{
	switch (keyPressed)
	{
	case Input::Key::W:
		if (playerRow > 0) 
		{
			//Borramos posición actual del jugador.
			mapa.modifyMap(playerRow, playerColumn, '.'); 
			//Actualizamos posición del jugador según el input.
			playerRow--; 
			//En caso de ir a casilla ocupada por moneda incrementamos puntuación y actualizamos la celda.
			if (mapa.map[playerRow][playerColumn] == '$') {
				score++;
				coins->updateCoins(playerRow, playerColumn, mapa);
			}
			//En caso de ir a casilla vacía actualizamos la posición del jugador en pantalla.
			else mapa.modifyMap(playerRow, playerColumn, '@');
		}
		break;
	case Input::Key::A:
		if (playerColumn > 0) 
		{
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
		if (playerRow < mapa.numRows-1) 
		{
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
		if (playerColumn < mapa.numColumns-1)
		{
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

