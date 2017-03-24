#pragma once
enum class Difficulty { N, EASY, MEDIUM, HARD }; ///Va al main? ///Es pot posar a la capçalera de la classe MAP i utilitzarla al main

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
	void printMap();
	void modifyMap(int Row, int Column, char content);
};

