#pragma once
#include "Map.h"
#include "Input.h"

class Player 
{
	int playerRow, playerColumn; //Coordenadas posición del jugador
public:
	int score; //Almacena puntuación del jugador
	Player(Map mapa);
	~Player();
	void updatePlayer(Map mapa, Input::Key keyPressed, CoinManager *coins); //Actualiza posición del jugador según el input del teclado
};

