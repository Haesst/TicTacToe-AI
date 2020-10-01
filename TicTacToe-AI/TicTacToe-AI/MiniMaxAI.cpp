#include "MiniMaxAI.h"
#include "Game.h"

int MiniMaxAI::GetNextMove(const std::map<int, FieldSquare>* PlayField)
{
	NegaMax(PlayField, Game::CurrentPlayer, true);
    return DesiredMove;
}

int MiniMaxAI::NegaMax(const std::map<int, FieldSquare>* PlayField, Contestant* Contestant, bool StartCall)
{
	// If the current field has a winner, GetWinnerValue will return 1 if it's the given contestant
	// -1 if it's the opponent and 0 if no winner exist yet.
	int winnerValue = GetWinnerValue(PlayField, Contestant);

	if (winnerValue != 0)
	{
		return winnerValue;
	}

	// Set score to -2 (-1 is an opponent win) and move to -1
	int score = -2;
	int move = -1;

	// Loop through every possible play
	for (int i = 1; i <= Game::GameWidth * Game::GameWidth; i++)
	{
		// Only check if the current index has a empty character
		if (PlayField->at(i).CurrentSymbol == Game::EmptyChar)
		{
			// Create a copy of the playfield to allow editing.
			std::map<int, FieldSquare> FieldWithNewMove = *PlayField;
			FieldWithNewMove[i].CurrentSymbol = Contestant->GetSymbol();

			// Get the score for the next move by negating the MegaMax score (Called NegaMaxing)
			int scoreForTheMove = -NegaMax(&FieldWithNewMove, Contestant == Game::CurrentPlayer ? Game::Opponent : Game::CurrentPlayer);

			// Check if the score is greater than the current score, if it is save it.
			if (scoreForTheMove > score)
			{
				score = scoreForTheMove;
				move = i;
			}
		}
	}

	// If it's a draw return a score of 0
	if (move == -1)
	{
		return 0;
	}

	DesiredMove = move;
	
	return score;
}

int MiniMaxAI::GetWinnerValue(const std::map<int, FieldSquare>* PlayField, Contestant* Contestant)
{
	if (Contestant == Game::CurrentPlayer)
	{
		if (Game::CheckWin(PlayField, Contestant))
		{
			return 1;
		}
		else if (Game::CheckWin(PlayField, Game::Opponent))
		{
			return -1;
		}
	}
	else
	{
		if (Game::CheckWin(PlayField, Contestant))
		{
			return -1;
		}
		else if (Game::CheckWin(PlayField, Game::Opponent))
		{
			return 1;
		}
	}

	return 0;
}
