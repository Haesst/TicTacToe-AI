#pragma once

#include <map>

#include "FieldSquare.h"

class Contestant
{
	char Symbol;

public:
	virtual int GetNextMove(const std::map<int, FieldSquare>* PlayField) = 0;
	virtual void SetSymbol(char symbol);
	virtual char GetSymbol();
};