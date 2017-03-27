#pragma once
#include "Map.h"
#include "Input.h"

class Player 
{
	int playerRow, playerColumn; //Coordenadas posici�n del jugador
public:
	int score; //Almacena puntuaci�n del jugador
	Player(Map mapa);
	~Player();
	void updatePlayer(Map mapa, Input::Key keyPressed, CoinManager *coins); //Actualiza posici�n del jugador seg�n el input del teclado
};

