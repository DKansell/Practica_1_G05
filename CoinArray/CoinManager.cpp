#include "CoinManager.h"
#include <iostream>
using namespace std;



CoinManager::CoinManager(Map mapa) :
	visibleCoins ((int)0.03*(mapa.numRows*mapa.numColumns) + rand() % (int)(0.1*(mapa.numRows*mapa.numColumns)))
{
	int coinX, coinY, coins = 0;

	do {
		
		coinX = rand() % mapa.numRows;
		coinY = rand() % mapa.numColumns;

		if (mapa.map[coinX][coinY] != '$')
		{
			mapa.modifyMap(coinX, coinY, '$');
			coins++;
		}
		
	} while (coins < visibleCoins);
};


CoinManager::~CoinManager()
{
}

void CoinManager::updateCoins(int x, int y, Map mapa) {

	if (visibleCoins > 0) {
		mapa.modifyMap(x, y, '.');
		visibleCoins--;
	}

	else CoinManager coins(mapa);

}
