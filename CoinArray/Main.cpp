#include "Map.h"
#include "Player.h"
#include "CoinManager.h"
#include "Input.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

//Sobrecarga del operador >> para castear un valor Difficulty a tipo int
std::istream& operator >>(std::istream &is, Difficulty& valor)
{
	int intVal;
	is >> intVal;
	valor = static_cast<Difficulty>(intVal);
	return is;
}

void main() 
{
	//Seed random
	srand(static_cast<unsigned>(time(nullptr)));

	Difficulty dificultat; 

	//Creación de las variables de control de tiempo
	std::clock_t start;
	double duration;
	
	//Instrucciones iniciales para el jugador y selección de dificultad
	std::cout << "Controls: Use WASD to move the player." << std::endl;
	std::cout << "\nChoose a difficulty: \n1 - EASY \n2 - MEDIUM \n3 - HARD" << std::endl;
	std::cin >> dificultat;
	

	//Constructores de los objetos de los ámbitos mapa, player y monedas.
	Map mapa(static_cast<int>(dificultat));
	CoinManager coins(mapa);
	Player player(mapa);

	//Determinación de las monedas totales a recoger
	int MAX_COINS = ((30 * static_cast<int>(dificultat)) + rand() % ((30 * static_cast<int>(dificultat) * 2) - (30 * static_cast<int>(dificultat))));

	std::cout << "\nObjective: You have to pick up " <<MAX_COINS<<" coins to win."<<std::endl;

	start = std::clock();

	//Variable donde guardamos el input de control del jugador
	Input::Key keyPressed;

	while (player.score < MAX_COINS) 
	{
		keyPressed = Input::getKey();

		if (keyPressed != Input::Key::NONE) 
		{
			player.updatePlayer(mapa, keyPressed, &coins);

			system("cls");
			mapa.printMap();
			std::cout << "\n\nScore: " << player.score << " / " << MAX_COINS << std::endl;
		}
		if (keyPressed == Input::Key::ESC) 
		{
			exit(0);
		}
	}

	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	
	std::cout << "\nYou've picked up " << MAX_COINS << " in " << duration << " seconds"<< std::endl;

	system("pause");
}