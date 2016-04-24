#pragma once

#include "Point.h"
#include "Piece.h"
#include "Desk.h"

enum Game_type { chess, barley};

class Game{

public:
	Game(Game_type game_type);
	virtual void move(Piece&) = 0;

private:
	Game_type _game_type;
	Desk<8> _desk;
	int _count_white;
	int _count_black;

};
