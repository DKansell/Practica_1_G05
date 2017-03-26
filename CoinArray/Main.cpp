#include "Map.h"
#include "Player.h"
#include "CoinManager.h"
#include "Input.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

std::istream& operator >>(std::istream &is, Difficulty& valor)
{
	int intVal;
	is >> intVal;
	valor = static_cast<Difficulty>(intVal);
	return is;
}

int main() {

	srand(static_cast<unsigned>(time(nullptr)));
	Difficulty dificultat; 
	
	std::cout << "Controls: Use WASD to move the player." << std::endl;
	std::cout << "\nChoose a difficulty: \n1 - EASY \n2 - MEDIUM \n3 - HARD" << std::endl;
	std::cin >> dificultat;
	

	//Constructor del objecte mapa: li pasem el paràmetre de la dificultat.
	Map mapa(static_cast<int>(dificultat));
	//Constructor del objete CoinManager, inicialitza les monedes al mapa.
	CoinManager coins(mapa);
	//Constructor del objecte player, inicialitza la posició inicial del jugador.
	Player player(mapa);

	//Determinem monedes a recollir per finalitzar el joc
	int MAX_COINS = ((30 * static_cast<int>(dificultat)) + rand() % ((30 * static_cast<int>(dificultat) * 2) - (30 * static_cast<int>(dificultat))));
	std::cout << "\nObjective: You have to pick up " <<MAX_COINS<<" coins to win."<<std::endl;

	//Tecla que apretarà el jugador
	Input::Key keyPressed;

	while (player.score < MAX_COINS) {

		keyPressed = Input::getKey();

		if (keyPressed != Input::Key::NONE) {
			player.updatePlayer(mapa, keyPressed, &coins);

			system("cls");
			mapa.printMap();
			std::cout << "\n\nScore: " << player.score << " / " << MAX_COINS << std::endl;
		}
	}
	
	// TEMPS: std::cout << "\nYou've picked up " << MAX_COINS << " in " << << "seconds"<< std::endl;

	system("pause");
}