#include "Game.h"

#include <iostream>
#include <string>

#include "Player.h"
#include "MiniMaxAI.h"
#include "AlphaBeta.h"

Contestant* Game::CurrentPlayer = nullptr;
Contestant* Game::Opponent = nullptr;
int Game::GameWidth = 3;

void Game::MainMenu()
{
    std::cout << "\x1B[2J\x1B[H";
    std::cout << "Welcome to TicTacToe" << std::endl;
    std::cout << "1: Play against another player." << std::endl;
    std::cout << "2: Play against AI. -Not implemented yet." << std::endl;
    std::cout << "3: Exit Game." << std::endl;

    int input = -1;

    std::cin >> input;

    if (std::cin.fail())
    {
        input = -1;
	}
	std::cin.clear(); std::cin.ignore(INT_MAX, '\n');

    switch (input)
    {
    case 1:
		std::cout << "Play against another player.\n";
		SetupGame(new Player(), new Player());
		DisplayMainMenu = false;
        GameRunning = true;
        break;
    case 2:
		std::cout << "Play against AI.\n";
		SetupGame(new Player(), new MiniMaxAI());
		DisplayMainMenu = false;
        GameRunning = true;
        break;
    case 3:
        EndGame = true;
        break;
    default:
        break;
    }
}

void Game::PrintBoard(const char* printMessage)
{
	std::cout << "\x1B[2J\x1B[H";
	int i = 1;
	for (int x = 0; x < GameWidth; x++)
	{
		for (int y = 0; y < GameWidth; y++)
		{
			if (PlayField[i].CurrentSymbol == EmptyChar)
			{
				std::cout << "(" << PlayField[i].FieldIndex << ")";
			}
			else
			{
				std::cout << ' ' << PlayField[i].CurrentSymbol << ' ';
			}

			if (i % GameWidth == 0)
			{
				std::cout << "\n";
			}

			i++;
		}
	}

	std::cout << "\n\n" << printMessage << std::endl;
}

bool Game::TryPlaceMarker(int desiredIndex)
{
	int i = 1;
	bool foundIndex = false;

	for (int x = 0; x < GameWidth; x++)
	{
		for (int y = 0; y < GameWidth; y++)
		{
			if (PlayField[i].FieldIndex == desiredIndex)
			{
				if (PlayField[i].CurrentSymbol != EmptyChar)
				{
					return false;
				}

				foundIndex = true;
				PlayField[i].CurrentSymbol = CurrentPlayer->GetSymbol();
			}

			if (foundIndex)
			{
				return true;
			}

			i++;
		}
		if (foundIndex)
		{
			return true;
		}
	}

	return false;
}

int Game::IsBoardFull()
{
	for (int i = 1; i <= GameWidth * GameWidth; i++)
	{
		if (PlayField[i].CurrentSymbol == EmptyChar)
		{
			return false;
		}
	}

	return true;
}

Game::Game()
{
	int i = 1;

	for (int x = 0; x < GameWidth; x++)
	{
		for (int y = 0; y < GameWidth; y++)
		{
			TTVector Position{ x, y };

            PlayField[i] = FieldSquare(Position, EmptyChar, i);
            i++;
		}
	}

    PlayerOne = nullptr;
    PlayerTwo = nullptr;
	CurrentPlayer = nullptr;
	GameWidth = 3;
}

void Game::SetupGame(Contestant* playerOne, Contestant* playerTwo)
{
	PlayerOne = playerOne;
	PlayerTwo = playerTwo;
	
	playerOne->SetSymbol('X');
	playerTwo->SetSymbol('O');

	int i = 1;

	for (int x = 0; x < GameWidth; x++)
	{
		for (int y = 0; y < GameWidth; y++)
		{
			TTVector Position{ x, y };

			PlayField[i] = FieldSquare(Position, EmptyChar, i);
			i++;
		}
	}

	CurrentPlayer = playerOne;
}

bool Game::CheckWin(const std::map<int, FieldSquare>* PlayField, Contestant* Contestant)
{
	if (CheckHorizontal(PlayField, Contestant) || CheckVertical(PlayField, Contestant) || CheckDiagonal(PlayField, Contestant))
	{
		return true;
	}

    return false;
}

bool Game::CheckHorizontal(const std::map<int, FieldSquare>* PlayField, Contestant* Contestant)
{
	// Check horizontal
	int i = 1;
	int hScore = 0;


	for (int row = 0; row < GameWidth; row++)
	{
		for (int column = 0; column < GameWidth; column++)
		{
			if (PlayField->at(i).CurrentSymbol == Contestant->GetSymbol())
			{
				hScore++;
			}
			i++;
		}


		if (hScore < GameWidth)
		{
			hScore = 0;
		}
		else
		{
			return true;
		}

	}

	return false;
}

bool Game::CheckVertical(const std::map<int, FieldSquare>* PlayField, Contestant* Contestant)
{

	// Check vertical
	int i = 1;
	std::map<int, int> vScore;

	for (int row = 0; row < GameWidth; row++)
	{
		for (int column = 0; column < GameWidth; column++)
		{
			if (PlayField->at(i).CurrentSymbol == Contestant->GetSymbol())
			{
				vScore[column]++;
			}
			i++;
		}
	}

	for (int x = 0; x < GameWidth; x++)
	{
		if (vScore[x] >= GameWidth)
		{
			return true;
		}
	}

	return false;
}

bool Game::CheckDiagonal(const std::map<int, FieldSquare>* PlayField, Contestant* Contestant)
{

	// Check Diagonal Left top to right bottom
	int dScore = 0;
	int i = 1;

	for (int row = 0; row < GameWidth; row++)
	{
		if (PlayField->at(i).CurrentSymbol == Contestant->GetSymbol())
		{
			dScore++;
		}
		i += GameWidth + 1;
	}

	if (dScore >= GameWidth)
	{
		return true;
	}

	dScore = 0;
	i = GameWidth;

	for (int row = 0; row < GameWidth; row++)
	{
		if (PlayField->at(i).CurrentSymbol == Contestant->GetSymbol())
		{
			dScore++;
		}
		i += GameWidth - 1;
	}

	if (dScore >= GameWidth)
	{
		return true;
	}

	return false;
}

void Game::Update()
{
    if (DisplayMainMenu)
    {
        MainMenu();
    }
    else if(GameRunning)
	{
        PrintBoard();

        int desiredIndex = CurrentPlayer->GetNextMove(&PlayField);

        if (TryPlaceMarker(desiredIndex))
        {
			if (CheckWin(&PlayField, CurrentPlayer))
			{
				PrintBoard((CurrentPlayer == PlayerOne) ? "Player One Wins!" : "Player Two Wins!");
				
				system("pause");
				DisplayMainMenu = true;
			}
			else
			{
				if (IsBoardFull())
				{
					PrintBoard("We have a draw!");

					system("pause");
					DisplayMainMenu = true;
				}
				else
				{
					CurrentPlayer = CurrentPlayer == PlayerOne ? PlayerTwo : PlayerOne;
					Opponent = CurrentPlayer == PlayerOne ? PlayerTwo : PlayerOne;
				}
			}
        }
	}
}
