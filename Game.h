#pragma once

#include "Point.h"
#include "Piece.h"
#include "Desk.h"

class Game{

public:
	Game() : cur_color_move(white) {};
	virtual void move(const Piece*, const Point& from, const Point& to) {};
	virtual void ChoiseOfPlayer(); //action in game
	virtual bool EndOfGame();
protected:
	Desk<8> _desk;
	int _count_white;
	int _count_black;
private:
	bool choise;
	Piece_color cur_color_move;

};

class ChessGame : public Game
{
public:
	ChessGame();
	void move(const Piece* p, const Point& from, const Point& to);
private:
	static const int CHESS_COLUMN = 2;
	static const int FIGURES_PER_ROW = 8;	
};
