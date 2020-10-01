// TicTacToe-AI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
//#include <map>
//
//#include "TTVector.h"
//#include "FieldSquare.h"

#include <memory>

#include "Game.h"

int main()
{
	std::unique_ptr<Game> game = std::make_unique<Game>();

	while (!game->EndGame)
	{
		game->Update();
	}
	/*
    std::map<TTVector, FieldSquare> PlayField;
    // FieldSquare PlayField[9];

    int i = 0;

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            TTVector Position{ x, y };

            PlayField[Position] = FieldSquare(Position, 'X');
        }
    }

    i = 0;

	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			TTVector currentPosition{ x,y };

			std::cout << PlayField[currentPosition].CurrentSymbol;
			i++;

			if (i == 3)
			{
				std::cout << '\n';
				i = 0;
			}
			else
			{
				std::cout << ' ';
			}
		}
	}

    std::cout << "Hello World!\n";
	*/
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
