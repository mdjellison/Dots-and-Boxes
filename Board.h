#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include "Box.h"
#include "HorizontalLine.h"
#include "VerticalLine.h"

class Board
{
public:
	Board();
	~Board();

	void createBoard();
	int numLines();
	int getNumColumns();
	int getNumRows();
	void displayBoard();

	bool createHorizLine(const int &index);
	bool createVertLine(const int &index);
	void formBox(const int &lineType, const int &index, const int &player);
	bool checkNewBox();

private:
	int boardWidth;
	int boardHeight;
	int numBoxes;
	std::vector<Box> boxes;
	std::vector<HorizontalLine> horizLines;
	std::vector<VerticalLine> vertLines;
};

