#pragma once
#include "Player.h"
#include "Board.h"
#include <vector>
#include <iostream>

class GameMaster
{
public:
	GameMaster();
	~GameMaster();
	void setPlayers();

	//Board wrapper functions
	void createBoard();
	int numLines();
	int getNumColumns();
	int getNumRows();
	void displayBoard();

	void playTurn(int numColumns, int numRows);
	void displayScores();

private:
	int turn;
	Board board;
	std::vector<Player> scoreBoard;
};

