#pragma once

#include "Point.h"
#include "Piece.h"
#include "Desk.h"

static const int CHESS_COLUMN = 2;		//���������� ����� ��� ��������� �����
static const int FIGURES_PER_ROW = 8;	//���������� ��������� �����

enum Game_type {chess, barley};

class Game{

public:
	//Game();
	Game(Game_type game_type);
	void move(Piece&);
	void ChoiseOfPlayer(Piece_color);

private:
	Game_type _game_type;
	Desk<8> _desk;
	int _count_white;
	int _count_black;
	bool choise;
};

Game::Game(Game_type game_type) : _game_type(game_type)
{
	if (_game_type == Game_type::chess)
	{
		Init(_desk);
		_count_white = CHESS_COLUMN * FIGURES_PER_ROW;//���������� �� ������� ���
		_count_black = CHESS_COLUMN * FIGURES_PER_ROW;
	}

	if (_game_type == Game_type::barley)
	{
		//�� ����������
	}
	
	ChoiseOfPlayer(Piece_color::white);
}

void Game::ChoiseOfPlayer(Piece_color color)
{
	cout << _desk;

}