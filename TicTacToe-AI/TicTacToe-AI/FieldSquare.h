#pragma once

#include "TTVector.h"

struct FieldSquare
{
	TTVector Position;
	char CurrentSymbol;
	int FieldIndex;

	FieldSquare(TTVector Position, char CurrentSymbol, int FieldIndex): Position(Position), CurrentSymbol(CurrentSymbol), FieldIndex(FieldIndex) {}
	FieldSquare() : CurrentSymbol(' '), FieldIndex(-1) {}
};
