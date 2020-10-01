#pragma once
#include "Contestant.h"
class AlphaBeta : public Contestant
{
private:
	const int MIN = -100000;
	const int MAX = 100000;
	int DesiredMove = -1;

private:
	int NegaMax(const std::map<int, FieldSquare>* PlayField, Contestant* Contestant, int depth, int alpha, int beta, bool StartCall = false);
	int GetWinnerValue(const std::map<int, FieldSquare>* PlayField, Contestant* Contestant);

public:
	virtual int GetNextMove(const std::map<int, FieldSquare>* PlayField) override;
};

