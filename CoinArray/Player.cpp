#include "Player.h"
#include "Map.h"
#include "CoinManager.h"
#include <iostream>


Player::Player(Map mapa) :
	score (0) //Inicializamos la puntuaci�n a 0.
{
	int auxRow, auxColumn; ///Variables auxiliares para el bucle de posicionamiento inicial.
	bool foundCoin = true; 

	//Determinamos posici�n inicial del jugador al azar sin que coincida con una moneda.
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
			//Borramos posici�n actual del jugador.
			mapa.modifyMap(playerRow, playerColumn, '.'); 
			//Actualizamos posici�n del jugador seg�n el input.
			playerRow--; 
			//En caso de ir a casilla ocupada por moneda incrementamos puntuaci�n y actualizamos la celda.
			if (mapa.map[playerRow][playerColumn] == '$') {
				score++;
				coins->updateCoins(playerRow, playerColumn, mapa);
			}
			//En caso de ir a casilla vac�a actualizamos la posici�n del jugador en pantalla.
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

