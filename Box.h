#pragma once
#include <iostream>
#include <iomanip>

class Box
{
public:
	Box();
	~Box();

	void flipUp(const int &owner);
	void flipDown(const int &owner);
	void flipLeft(const int &owner);
	void flipRight(const int &owner);

	void drawBox(const int &player);
	bool checkDrawn();
	void printBox();

private:
	bool up;
	bool down;
	bool left;
	bool right;
	bool drawn;
	int owner;
};

