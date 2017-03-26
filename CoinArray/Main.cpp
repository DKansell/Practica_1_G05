#include "Map.h"
#include <iostream>
#include <ctime>
#include "Player.h"
#include "CoinManager.h"

int main() {

	srand(static_cast<unsigned>(time(nullptr)));
	
	Difficulty dificultat; //S'haura de cridar amb static cast
	//cin >> ....

	//Constructor del objecte mapa: li pasem el parÓmetre de la dificultat.
	Map mapa(2);
	

	CoinManager coins(mapa);

	//Constructor del objecte player
	Player player(mapa);

	mapa.printMap();
	
	system("pause");
}