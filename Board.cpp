#include "Board.h"

enum InputType
{
	vertLine,
	horizLine,
	illegalInput
};

Board::Board()
	:boardWidth(0),
	boardHeight(0),
	boxes(0),
	numBoxes(0),
	horizLines(0),
	vertLines(0)
{
}

Board::~Board()
{
}

void Board::createBoard()
{
	std::cout << "Select game board dimensions." << std::endl;

	std::cout << "Board Width (Number of Boxes):" << std::endl;
	const int maxWidth = 12;
	while (boardWidth > maxWidth || boardWidth <= 0)
	{
		std::cin >> boardWidth;
		if (boardWidth > maxWidth || boardWidth <= 0)
		{
			std::cout << "Board width must be between 1 and 12 boxes." << std::endl;
		}
	}

	std::cout << "Board Height (Number of Boxes):" << std::endl;
	const int maxHeight = 49;
	while (boardHeight > maxHeight || boardHeight <= 0)
	{
		std::cin >> boardHeight;
		if (boardHeight > maxHeight || boardHeight <= 0)
		{
			std::cout << "Board height must be between 1 and 49 boxes." << std::endl;
		}
	}

	boxes.resize(boardWidth * boardHeight);
	horizLines.resize(boardWidth * (boardHeight + 1));
	vertLines.resize((boardWidth + 1) * boardHeight);
}

int Board::numLines()
{
	const int numLines = horizLines.size() + vertLines.size();
	return numLines;
}

int Board::getNumColumns()
{
	return 2 * boardWidth + 1;
}

int Board::getNumRows()
{
	return 2 * boardHeight + 1;
}

void Board::displayBoard()
{
	char ch = 'A';
	//Print column labels
	std::cout << " " << " " << " ";
	for (int count = 0; count < 2 * boardWidth + 1; ++count)
	{
		std::cout << ch << "  ";
		++ch;
	}
	std::cout << '\n';

	int horizIndex = 0;
	int vertIndex = 0;
	int boxIndex = 0;
	int rowNumber = 1;

	//First row
	std::cout << std::setw(2) << rowNumber++ << " ";
	for (int j = 0; j < boardWidth; ++j)
	{
		std::cout << "*";
		horizLines[horizIndex++].printLine();
	}
	std::cout << "*";
	std::cout << '\n';

	//Each other row (two at a time)
	for (int i = 0; i < boardHeight; ++i)
	{
		std::cout << std::setw(2) << rowNumber++ << " ";
		for (int k = 0; k < boardWidth; ++k)
		{
			vertLines[vertIndex++].printLine();
			boxes[boxIndex++].printBox();
		}
		vertLines[vertIndex++].printLine();
		std::cout << '\n';

		std::cout << std::setw(2) << rowNumber++ << " ";
		for (int j = 0; j < boardWidth; ++j)
		{
			std::cout << "*";
			horizLines[horizIndex++].printLine();
		}
		std::cout << "*";
		std::cout << '\n';
	}
}

bool Board::createHorizLine(const int &index)
{
	bool success = horizLines[index].showLine();
	return success;
}

bool Board::createVertLine(const int &index)
{
	bool success = vertLines[index].showLine();
	return success;
}

//Algorithm that takes line type and index, and flips correct boolean values in corresponding box vector
void Board::formBox(const int &lineType, const int &lineIndex, const int &player)
{
	if (lineType == horizLine)
	{
		if (lineIndex < boardWidth)
		{
			boxes[lineIndex].flipUp(player);
		}
		else if (lineIndex >= boxes.size())
		{
			boxes[lineIndex - boardWidth].flipDown(player);
		}
		else
		{
			boxes[lineIndex].flipUp(player);
			boxes[lineIndex - boardWidth].flipDown(player);
		}
	}

	if (lineType == vertLine)
	{
		int rowNumber = (lineIndex / (boardWidth + 1)) + 1;

		if (lineIndex % (boardWidth + 1) == 0)
		{
			boxes[lineIndex - (rowNumber - 1)].flipLeft(player);
		}
		else if (lineIndex == (boardWidth*rowNumber) + (rowNumber - 1))
		{
			boxes[lineIndex - rowNumber].flipRight(player);
		}
		else
		{
			boxes[lineIndex - (rowNumber - 1)].flipLeft(player);
			boxes[lineIndex - rowNumber].flipRight(player);
		}
	}
}

bool Board::checkNewBox()
{
	int boxCount = 0;
	int totNumBoxes = boxes.size();
	for (int i = 0; i < totNumBoxes; ++i)
	{
		if (boxes[i].checkDrawn() == true)
		{
			boxCount++;
		}
	}

	if (boxCount > numBoxes)
	{
		++numBoxes;
		return true;
	}
	else return false;
}
