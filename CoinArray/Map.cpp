#include "Map.h"



Map::Map(int dificultat, int numRows, int numColumns)
{
	//Inicializamos la dimension de las filas y columnas segun la dificultad
	numRows = 5 * dificultat;
	numColumns = 5 * dificultat * 2;

	//Reservamos memoria para el mapa
	char **map;
	map = new char *[numRows]; ///Punteros a cada fila

	for (int i = 0; i < numRows; i++)
		map[i] = new char[numColumns]; ///Punteros de columnas para cada fila

									   //Inicializamos todas las celdas vacias 
	for (int i = 0; i < numRows; i++)
		for (int j = 0; i < numColumns; j++)
			map[i][j] = '.';
}

//Destructor
Map::~Map()
{
}
