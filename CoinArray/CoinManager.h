#pragma once
#include "Map.h"

class CoinManager
{
	friend class Player;
public:
	int visibleCoins;

	CoinManager(Map mapa);
	~CoinManager();

	void updateCoins (int x, int y, Map mapa);
};

