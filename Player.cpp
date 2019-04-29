#include "Player.h"

enum InputType
{
	vertLine,
	horizLine,
	illegalInput
};

Player::Player()
	:score(0)
{
}


Player::~Player()
{
}

int Player::findLineType(const int &rowInput, const int &columnInput)
{
	enum RowType
	{
		even,
		odd
	};

	if (rowInput % 2 == even && columnInput % 2 == odd)
	{
		return vertLine;
	}
	else if (rowInput % 2 == odd && columnInput % 2 == even)
	{
		return horizLine;
	}
	else
	{
		return illegalInput;
	}
}

int Player::placeLine(const int &numColumns, const int &numRows, int &lineType)
{
	int rowInput = 0;
	char columnInput = '\0';

	do
	{
		//Would like to restrict user input here that is not a row and column, but I ran out of time.
		//I was looking into using regex to do this.
		std::cin >> rowInput >> columnInput;
		if (columnInput >= 'a' && columnInput <= 'z')
		{
			columnInput = toupper(columnInput);
		}

		if (rowInput <= 0 || rowInput > numRows || columnInput < 'A' || (columnInput - 'A') > numColumns)
		{
			std::cout << "Location lies outside of the board dimensions. Please try again." << std::endl;
		}
		std::cout << "Row is: " << rowInput << std::endl;
		std::cout << "Column is: " << columnInput << std::endl;

		lineType = findLineType(rowInput, columnInput);

		if (lineType == illegalInput)
		{
			std::cout << "Row/column location does not contain a line. Please try again." << std::endl;
		}
	} while (rowInput <= 0 || rowInput > numRows || columnInput < 'A' || (columnInput - 'A') > numColumns || lineType == illegalInput);
	

	//Algorithm for determining index of line vector
	if (lineType == vertLine)
	{
		int index = 0;
		int linesPerRow = (numColumns + 1) / 2;

		for (int rowCount = 0; rowCount < (rowInput + 1) / 2; ++rowCount)
		{
			if (rowCount < (rowInput - 2) / 2)
			{
				index = index + linesPerRow;
			}
			else
			{
				for (int columnCount = 0; columnCount < (columnInput - 'A') / 2; ++columnCount)
				{
					++index;
				}
			}
		}
		return index;
	}

	if (lineType == horizLine)
	{
		int index = 0;
		int linesPerRow = (numColumns - 1) / 2;
		for (int rowCount = 0; rowCount < (rowInput + 1) / 2; ++rowCount)
		{
			if (rowCount < rowInput / 2)
			{
				index = index + linesPerRow;
			}
			else
			{
				for (int columnCount = 0; columnCount < (columnInput - 'A') / 2; ++columnCount)
				{
					++index;
				}
			}
		}
		return index;
	}
}

void Player::addPoint()
{
	score++;
}

int Player::giveScore()
{
	return score;
}