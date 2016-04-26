#pragma once

#include "Point.h"
#include "Piece.h"
#include "Desk.h"

enum Game_type { chess, barley};

class Game{

public:
	Game();
	Game(Game_type game_type);
	virtual void move(Piece&) = 0;

private:
	Game_type _game_type;
	Desk<8> _desk;
	int _count_white;
	int _count_black;

};

class Chess_Game{
public:
	Chess_Game(); 
};

class Barley_Game{
public:
	Barley_Game();
};

Game::Game()
{
	int choose;
	std::cout << "Choose the game type:(chess=0;barley=1;exit=2)" << std::endl;	
	std::cin >> choose;
	switch (choose)
	{
	case 0: Chess_Game();
	case 1:	Barley_Game();
	case 2: exit(0);			
	}
}