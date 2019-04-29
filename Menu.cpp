#include "Menu.h"


Menu::Menu()
	:quit(false)
{
}


Menu::~Menu()
{
}

void Menu::callMenu()
{
	std::cout << std::endl;
	std::cout << "  *  *  *  *  *" << '\n' << '\n' << "  *  *  *  *  *" << '\n' << '\n' << "  *  *  *  *  *" << '\n' << '\n' << "  *  *  *  *  *" << '\n' << '\n' << "  *  *  *  *  *" << std::endl;
	std::cout << "Welcome to Dots and Boxes!!" << std::endl;
	std::cout << "Enter any key to play or enter 'q' to quit." << std::endl;
	char choice = '\0';
	std::regex inputCheck("");

	//I would like to reject input here that doesn't follow the correct type and length, but I ran out of time to do this.
	//I was looking into using regex here.
	std::cin >> choice;

	if (choice == 'q' || choice == 'Q')
	{
		quit = true;
	}
	else quit = false;
}

bool Menu::quitGame()
{
	return quit;
}
