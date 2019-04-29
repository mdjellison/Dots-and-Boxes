#include "VerticalLine.h"

VerticalLine::VerticalLine()
	:isPresent(false)
{
}


VerticalLine::~VerticalLine()
{
}

bool VerticalLine::showLine()
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

void VerticalLine::printLine()
{
	if (isPresent)
	{
		std::cout << "|";
	}
	else std::cout << " ";
}