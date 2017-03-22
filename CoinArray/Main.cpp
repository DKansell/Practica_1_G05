#include "Map.h"
#include <iostream>
#include <ctime>
#include "Player.h"

int main() {

	srand(static_cast<unsigned>(time(nullptr)));
	
	Difficulty dificultat; //S'haura de cridar amb static cast
	//cin >> ....

	Map mapa(2);//Constructor del objecte mapa: li pasem el paràmetre de la dificultat.
	mapa.printMap();

	Player player (mapa.numRows, mapa.numColumns);
	

	system("pause");
}