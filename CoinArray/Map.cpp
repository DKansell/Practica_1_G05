#include "Map.h"
#include <iostream>


Map::Map(int dificultat) :
	//Inicializamos la dimension de las filas y columnas segun la dificultad
	numRows ((5 * dificultat) + rand() % ((5 * dificultat * 2)-(5 * dificultat))),
	numColumns ((5 * dificultat) + rand() % ((5 * dificultat * 2)-(5 * dificultat)))
{
	//Reservamos memoria para el mapa
	map = new char *[numRows]; ///Punteros a cada fila

	for (int i = 0; i < numRows; i++)
		map[i] = new char[numColumns]; ///Punteros de columnas para cada fila

	//Inicializamos todas las celdas vacias 
	for (int i = 0; i < numRows; i++)
		for (int j = 0; j < numColumns; j++)
			map[i][j] = '.';
};

//Destructor
Map::~Map()
{
}


void Map::modifyMap(int row, int column, char content) {

	map[row][column] = content;

}

void Map::printMap() {

	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numColumns; j++) {
			std::cout << map[i][j] << " ";
		}
		std::cout << "\n";
	}

}
