#pragma once
#include <iostream>
#include <regex>

class Menu
{
public:
	Menu();
	~Menu();

	void callMenu();
	bool quitGame();

private:
	bool quit;
};

