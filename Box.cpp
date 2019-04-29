#include "Box.h"

Box::Box()
	:up(false),
	down(false),
	left(false),
	right(false),
	drawn(false),
	owner(1)
{
}

Box::~Box()
{
}

void Box::flipUp(const int &player)
{
	up = true;
	drawBox(player);
}

void Box::flipDown(const int &player)
{
	down = true;
	drawBox(player);
}

void Box::flipLeft(const int &player)
{
	left = true;
	drawBox(player);
}

void Box::flipRight(const int &player)
{
	right = true;
	drawBox(player);
}

void Box::drawBox(const int &player)
{
	if (up == true && down == true && left == true && right == true)
	{
		drawn = true;
		owner = player;
	}
}

bool Box::checkDrawn()
{
	if (drawn == true) return true;
	else return false;
}

void Box::printBox()
{
	if (drawn)
	{
		std::cout << std::setw(3) << "p" << " " << owner;
	}
	else std::cout << "     ";
}
