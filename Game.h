#pragma once

#include "Point.h"
#include "Piece.h"
#include "Desk.h"

class Game{

public:
	Game() : cur_color_move(white) {};
	virtual void move(const Piece*, const Point& from, const Point& to) {};
	virtual void InitDesk() {}; //initialize desk
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
friend Piece_type piece_type(const Point& p);

public:
	ChessGame();
	virtual void InitDesk(Desk<8>& desk); //можно ли прописать в таком варианте template? не хочу зависеть на числе "<8>"
	virtual void move(const Piece* p, const Point& from, const Point& to);
private:
	static const int FIGURES_ROW = 2;
	static const int FIGURES_ON_ROW = 8;	
};
