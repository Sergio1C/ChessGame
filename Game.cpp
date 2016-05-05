#include "Game.h"

void Game::ChoiseOfPlayer()
{
	cout << _desk;

	Point p_from, p_to;
	const Piece* cur_piece = 0;
	const Piece* to_piece = 0;
	stringstream play_color;

	while (!EndOfGame())
	{
		play_color.clear();
		play_color.str(cur_color_move == white ? "WHITE:" : "BLACK:");

		cout << play_color.str() << "1.Choise you piece (x,y):";
		cin >> p_from;

		cur_piece = _desk.piece(p_from);
		if (cur_piece == nullptr || cur_piece->get_color() != cur_color_move)
		{
			cout << play_color.str() << "Wrong choise or current color of piece. Try again" << endl;
			continue;
		}

		cout << play_color.str() << "2.You piece is:" << cur_piece << ".Move to (x,y):";
		cin >> p_to;

		to_piece = _desk.piece(p_to);
		if (cur_piece->chek_move(p_from, p_to) && to_piece == nullptr ? true : to_piece->get_color() != cur_color_move)
		{
			move(cur_piece, p_from, p_to);
			system("cls");
			cout << _desk;
			cur_color_move = (cur_color_move == white ? black : white);
		}
		else
			cout << play_color.str() << "Wrong move.Choise again." << endl;

	}
	return;
}

bool Game::EndOfGame()
{
	return (_count_black == 0 || _count_white == 0);
}

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