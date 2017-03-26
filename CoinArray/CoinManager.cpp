#include "CoinManager.h"
#include <iostream>

using namespace std;



CoinManager::CoinManager(Map mapa) 

{
	drawCoins(mapa);
};


CoinManager::~CoinManager()
{
}

void CoinManager::drawCoins(Map mapa) {

	visibleCoins=(int)0.03*(mapa.numRows*mapa.numColumns) + rand() % (int)(0.1*(mapa.numRows*mapa.numColumns));
	int coinRow, coinColumn;
	int count = 0;
	
	do {

		coinRow = rand() % mapa.numRows;
		coinColumn = rand() % mapa.numColumns;

		if (mapa.map[coinRow][coinColumn] != '$')
		{
			mapa.modifyMap(coinRow, coinColumn, '$');
			count++;
		}

	} while (count < visibleCoins);
}

void CoinManager::updateCoins(int row, int column, Map mapa) {
		mapa.modifyMap(row, column, '.');
		visibleCoins--;
		if (visibleCoins == 0) drawCoins(mapa);
}

