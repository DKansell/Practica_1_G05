#include "Map.h"
#include <iostream>
#include <ctime>

int main() {

	srand(static_cast<unsigned>(time(nullptr)));
	
	Difficulty dificultat; //S'haura de cridar amb static cast


	Map mapa(2);
	mapa.printMap();
	

	system("pause");
}