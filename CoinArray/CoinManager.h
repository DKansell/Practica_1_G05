#pragma once
#include "Map.h"

class CoinManager
{
	friend class Player;
	int visibleCoins; //Monedas visibles en el mapa
public:
	CoinManager (Map mapa); 
	~CoinManager();
	void drawCoins(Map mapa); //Inicializa las monedas dentro del mapa
	void updateCoins (int row, int column, Map mapa); //Elimina una moneda o genera un nuevo conjunto
};

