#include "HorizontalLine.h"


HorizontalLine::HorizontalLine()
	:isPresent(false)
{
}


HorizontalLine::~HorizontalLine()
{
}

bool HorizontalLine::showLine()
{
	if (isPresent)
	{
		return false;
	}
	else
	{
		isPresent = true;
		return true;
	}
}

void HorizontalLine::printLine()
{
	if (isPresent)
	{
		std::cout << "-----";
	}
	else std::cout << "     ";
}

