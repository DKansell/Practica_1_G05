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
	void printMap();
	void modifyMap(int row, int column, char content);
};

