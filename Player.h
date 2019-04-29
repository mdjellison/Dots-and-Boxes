#pragma once
#include <iostream>

class Player
{
public:
	Player();
	~Player();

	int placeLine(const int &numColumns, const int &numRows, int &lineType);
	void addPoint();
	int giveScore();

private:
	int score;
	int findLineType(const int &rowInput, const int &columnInput);
};

