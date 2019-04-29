#include "GameMaster.h"

enum InputType
{
	vertLine,
	horizLine,
	illegalInput
};

GameMaster::GameMaster()
	:turn(0),
	scoreBoard(0)
{
}

GameMaster::~GameMaster()
{
}

//Wrapper functions to access board functions
void GameMaster::createBoard()
{
	board.createBoard();
}

int GameMaster::numLines()
{
	return board.numLines();
}

int GameMaster::getNumColumns()
{
	return board.getNumColumns();
}

int GameMaster::getNumRows()
{
	return board.getNumRows();
}

void GameMaster::displayBoard()
{
	board.displayBoard();
}

void GameMaster::setPlayers()
{
	int numPlayers;

	do {
		std::cout << "Please enter the number of players: " << std::endl;
		std::cin >> numPlayers;
		scoreBoard.resize(numPlayers);
		if (numPlayers > 10)
		{
			std::cout << "Wow! " << numPlayers << " players is kind of a lot! Why not try playing with 10 or less?" << std::endl;
		}
		if (numPlayers <= 0)
		{
			std::cout << "You need at least one player to play the game!" << std::endl;
		}
	} while (numPlayers > 10 || numPlayers <= 0);
}

void GameMaster::playTurn(int numColumns, int numRows)
{
	int lineType = 0;
	bool successfulPlacement = false;
	int index = 0;
	std::cout << "Player " << turn << ", please choose a row and column location to place a line. (ex. 10A)" << std::endl;

	do {
		index = scoreBoard[turn].placeLine(numColumns, numRows, lineType);

		if (lineType == vertLine)
		{
			successfulPlacement = board.createVertLine(index);
		}

		if (lineType == horizLine)
		{
			successfulPlacement = board.createHorizLine(index);
		}

		if (successfulPlacement == false)
		{
			std::cout << "A line is already placed there. Please try again." << std::endl;
		}
	} while (successfulPlacement == false);
	
	board.formBox(lineType, index, turn);

	if (!board.checkNewBox())
	{
		turn = ++turn % scoreBoard.size();
	}
	else
	{
		scoreBoard[turn].addPoint();
	}
}

void GameMaster::displayScores()
{
	for (int i = 0; i < scoreBoard.size(); ++i)
	{
		std::cout << "Player " << i << ": " << scoreBoard[i].giveScore() << "points!" << std::endl;
	}
}