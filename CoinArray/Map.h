#pragma once
enum class Difficulty { N, EASY, MEDIUM, HARD }; ///Va al main?

class Map
{
public:

	int numRows;
	int numColumns;
	char **map;

	Map(int dificultat);
	~Map();
	void printMap();
};

