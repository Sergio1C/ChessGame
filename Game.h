#pragma once

#include "Point.h"
#include "Piece.h"
#include "Desk.h"

class Game{

public:
	Game();
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

Game::Game() : cur_color_move(Piece_color::white)
{}

class ChessGame : public Game
{
public:
	ChessGame();
	void move(const Piece* p, const Point& from, const Point& to);
private:
	static const int CHESS_COLUMN = 2;
	static const int FIGURES_PER_ROW = 8;	
};

ChessGame::ChessGame() {
	Game();
	Init(_desk);
	_count_white = CHESS_COLUMN * FIGURES_PER_ROW;
	_count_black = CHESS_COLUMN * FIGURES_PER_ROW;
	ChoiseOfPlayer();
}

void ChessGame::move(const Piece* piece, const Point& from, const Point& to)
{
	_desk.piece(to, piece);
	_desk.piece(from, nullptr);
}

bool Game::EndOfGame()
{
	return (_count_black == 0 || _count_white == 0);
}

void Game::ChoiseOfPlayer()
{
	cout << _desk;

	Point p_from, p_to;
	const Piece* cur_piece = 0;

	while (!EndOfGame())
	{
		string strColor = (cur_color_move == white ? "WHITE" : "BLACK");
		cout << strColor.c_str() << endl;
		
			cout << "1.choise you piece (x,y):";
			cin >> p_from;
			
			cur_piece = _desk.piece(p_from);
			if (cur_piece == nullptr)
			{
				cout << "Wrong choise." << endl;
				continue;
			}

			cout << "2.You piece is:" << cur_piece << ". moved to (x,y):";
			cin >> p_to;
			if (cur_piece->chek_move(p_from, p_to))
			{
				move(cur_piece, p_from, p_to);
				system("cls");
				cout << _desk;
				cur_color_move = (cur_color_move == white ? black : white);

			}
			else
				cout << "wrong move.Choise again" << endl;

	}
	return;
}
