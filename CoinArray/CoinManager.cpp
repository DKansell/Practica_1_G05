#include "CoinManager.h"
#include <iostream>


//Constructor, realiza la llamada inicial a drawCoins para inicializar monedas en el mapa.
CoinManager::CoinManager(Map mapa) 
{
	drawCoins(mapa);
};


CoinManager::~CoinManager()
{
}

void CoinManager::drawCoins(Map mapa) 
{
	//Monedas visibles al azar, varian entre 3% y 13% del tamaño del mapa.
	visibleCoins= static_cast <int>(0.03*(mapa.numRows*mapa.numColumns)) + rand() % (static_cast <int>(0.1*(mapa.numRows*mapa.numColumns)));
	int coinRow, coinColumn;
	int count = 0;
	
	while (count < visibleCoins) {

		coinRow = rand() % mapa.numRows;
		coinColumn = rand() % mapa.numColumns;

		if (mapa.map[coinRow][coinColumn] == '.')
		{
			mapa.modifyMap(coinRow, coinColumn, '$');
			count++;
		}
	} 
}

void CoinManager::updateCoins(int row, int column, Map mapa) 
{
		mapa.modifyMap(row, column, '@');
		visibleCoins--;
		//En caso de haber recogido todas las monedas se vuelve a llamar a drawCoins para generar de nuevas.
		if (visibleCoins <= 0) drawCoins(mapa);
}


