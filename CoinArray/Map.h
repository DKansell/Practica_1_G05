#pragma once
class Map
{
public:
	enum class Difficulty { NULL, EASY, MEDIUM, HARD }; ///Va al main?
	Difficulty dificultat;
	int numRows;
	int numColumns;
	Map(int dificultat, int numRows, int numColumns);
	~Map();
};
