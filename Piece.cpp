#include "Piece.h"

Piece::Piece(Piece_color color): _color(color)
{}

Piece_color Piece::get_color() const
{
	return _color;
}

Pawn::Pawn(Piece_color color):Piece(color)
{
}

bool Pawn::chek_move(const Point& from, const Point& to) const
{
	int x_from = from.getX();
	int y_from = from.getY();
	int x_to = to.getX();
	int y_to = to.getX();
	//пусть пешка всегда ходит на один Point и только вертикально
	if (x_from != x_to) return false;
	if (abs(y_to - y_from) !=1) return false;
	return true;
}

Knight::Knight(Piece_color color):Piece(color)
{
}

bool Knight::chek_move(const Point& from, const Point& to) const
{
	int x_from = from.getX();
	int y_from = from.getY();
	int x_to = to.getX();
	int y_to = to.getX();
	//2 смещения по "y" и 1 по "x" или наоборот
	int dy = y_to - y_from;
	int dx = x_to - x_from;
	
	Point dPoint(dx, dy);
	Point xy[8] = { Point(2, 1), Point(1, 2), Point(-1, 2), Point(-2, -1), Point(-2, -1), Point(-1, -2), Point(1, -2), Point(2, -1) };

	//проверим смещение 
	for (int i = 0; i < 8; i++)
	{
		if (xy[i] == dPoint) return true;
	}
	return false;
}

ostream& operator<<(ostream& os, Piece& p)
{
	os << "[X]";
	return os;
}