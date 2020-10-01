#pragma once
#include "Contestant.h"

class MiniMaxAI : public Contestant
{
private: 
	int DesiredMove = -1;

private:
	int NegaMax(const std::map<int, FieldSquare>* PlayField, Contestant* Contestant, bool StartCall = false);
	int GetWinnerValue(const std::map<int, FieldSquare>* PlayField, Contestant* Contestant);

public:
	virtual int GetNextMove(const std::map<int, FieldSquare>* PlayField) override;

};

