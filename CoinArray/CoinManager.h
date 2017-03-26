#pragma once
#include "Map.h"


class CoinManager
{
	friend class Player;
public:
	int visibleCoins;
	int monedes;

	CoinManager(Map mapa);
	~CoinManager();

	void drawCoins(Map mapa);
	void updateCoins (int row, int column, Map mapa);
};

