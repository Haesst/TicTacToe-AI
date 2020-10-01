#include "Player.h"

#include <iostream>

int Player::GetNextMove(const std::map<int, FieldSquare>* PlayField)
{
	int input = -1;

	std::cin >> input;

	if (std::cin.fail())
	{
		input = -1;
	}
	std::cin.clear(); std::cin.ignore(INT_MAX, '\n');

	return input;
}
