#pragma once
enum class Difficulty { N, EASY, MEDIUM, HARD }; 

class Map
{
	friend class CoinManager;
	friend class Player;
	int numRows;
	int numColumns;
	char **map;
public:
	Map(int dificultat);
	~Map();
	void printMap(); //Imprime el mapa por pantalla
	void modifyMap(int row, int column, char content); //Modifica una celda del mapa (por el contenido deseado)
};

