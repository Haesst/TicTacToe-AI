#pragma once
#include "Contestant.h"

class Player : public Contestant
{
	// Inherited via Contestant
	virtual int GetNextMove(const std::map<int, FieldSquare>* PlayField) override;
};

