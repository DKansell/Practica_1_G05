#include "Map.h"
#include <iostream>
#include <ctime>
#include "Player.h"

int main() {

	srand(static_cast<unsigned>(time(nullptr)));
	
	Difficulty dificultat; //S'haura de cridar amb static cast
	//cin >> ....

	//Constructor del objecte mapa: li pasem el paràmetre de la dificultat.
	Map mapa(2);
	mapa.printMap();

	//Constructor del objecte player
	Player player;
	

	system("pause");
}