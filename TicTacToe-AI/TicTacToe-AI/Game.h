#pragma once

#include <map>

#include "TTVector.h"
#include "FieldSquare.h"

#include "Contestant.h"

class Game
{
private:
	std::map<int, FieldSquare> PlayField;
	Contestant* PlayerOne;
	Contestant* PlayerTwo;


	bool GameRunning = false;
	bool DisplayMainMenu = true;

public:
	bool EndGame = false;

	static const char EmptyChar = ' ';
	static int GameWidth;
	static Contestant* CurrentPlayer;
	static Contestant* Opponent;
    static bool CheckWin(const std::map<int, FieldSquare>* PlayField, Contestant* Contestant);

private:
	void MainMenu();
	void PrintBoard(const char* printMessage = "");
	bool TryPlaceMarker(int desiredIndex);
	int IsBoardFull();

	static bool CheckHorizontal(const std::map<int, FieldSquare>* PlayField, Contestant* Contestant);
	static bool CheckVertical(const std::map<int, FieldSquare>* PlayField, Contestant* Contestant);
	static bool CheckDiagonal(const std::map<int, FieldSquare>* PlayField, Contestant* Contestant);

public:
	Game();

	void SetupGame(Contestant* playerOne, Contestant* playerTwo);

	void Update();
};

