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

		cur_piece = &_desk.piece(p_from);
		if (cur_piece == nullptr || cur_piece->get_color() != cur_color_move)
		{
			cout << play_color.str() << "Wrong choise or current color of piece. Try again" << endl;
			continue;
		}

		cout << play_color.str() << "2.You piece is:" << cur_piece << ".Move to (x,y):";
		cin >> p_to;

		to_piece = &_desk.piece(p_to);
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
	InitDesk(_desk);
	_count_white = FIGURES_ROW * FIGURES_ON_ROW;
	_count_black = FIGURES_ROW * FIGURES_ON_ROW;
	ChoiseOfPlayer();
}

//template <int Size>
void ChessGame::InitDesk(Desk<8>& desk)
{
	int Size = 8;
	int count = Size - 1;
	//white rows
	static Piece_color cur_color = white;
	for (int i = 0; i < FIGURES_ROW; i++)
	{
		for (int j = 0; j < FIGURES_ON_ROW; j++)
		{
			
			Piece_type cur_type = piece_type(Point(i, j));
			if (cur_type == kind)
				desk.piece(Point(i, j), new Kind(cur_color));
			if (cur_type == knight)
				desk.piece(Point(i, j), new Knight(cur_color));
			if (cur_type == pawn)
				desk.piece(Point(i, j), new Pawn(cur_color));
		}
	}
	//black rows 
	cur_color = black;
	for (int i = count; i > count - FIGURES_ROW; i--)
	{
		for (int j = 0; j < FIGURES_ON_ROW; j++)
		{
			Piece_type cur_type = piece_type(Point(i, j));
			if (cur_type == kind)
				desk.piece(Point(i, j), new Kind(cur_color));
			if (cur_type == knight)
				desk.piece(Point(i, j), new Knight(cur_color));
			if (cur_type == pawn)
				desk.piece(Point(i, j), new Pawn(cur_color));
		}
	}
};

void ChessGame::move(const Piece* piece, const Point& from, const Point& to)
{
	_desk.piece(to, piece);
	_desk.delete_piece(from);
}

Piece_type piece_type(const Point& p)
{
	//начальные позиции фигур в игре 
	Point KnightPos[4] = { Point(0, 1), Point(0, 6), Point(7, 1), Point(7, 6) };

	for (int i = 0; i < 4; i++)
	{
		if (KnightPos[i].getX() == p.getX() && KnightPos[i].getY() == p.getY()) return knight;
	}
	
	Point KindPos[2] = { Point(0, 3), Point(7, 3) };
	for (int i = 0; i < 2; i++)
	{
		if (KindPos[i].getX() == p.getX() && KindPos[i].getY() == p.getY()) return kind;
	}

	return pawn;
}