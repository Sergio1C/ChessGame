#include "Piece.h"

Piece::Piece(Piece_color color): _color(color)
{}

Piece_color Piece::get_color() const
{
	return _color;
}

//Pawn
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

//Knight
Knight::Knight(Piece_color color):Piece(color)
{
}

bool Knight::chek_move(const Point& from, const Point& to) const
{
	int x_from = from.getX();
	int y_from = from.getY();
	int x_to = to.getX();
	int y_to = to.getX();
	//возможные смещения по "y"=2 и по "x"=2 или наоборот храним в массиве xy[8]
	int dy = y_to - y_from;
	int dx = x_to - x_from;
	
	 Point dPoint(dx, dy);
	 Point xy[8] = { Point(2, 1), Point(1, 2), Point(-1, 2), Point(-2, -1), Point(-2, -1), Point(-1, -2), Point(1, -2), Point(2, -1) };

	//проверим смещение 
	for (int i = 0; i < 8; i++)
	{
		//if (xy[i] == dPoint) return true;
	}
	return false;
}

ostream& operator<<(ostream& os, const Piece& p)
{
	
	os << p;
	return os;
}

ostream& operator<<(ostream& os, const Pawn& p)
{
	os << "[P]";
	return os;
}
ostream& operator<<(ostream& os, const Knight& p)
{
	os << "[K]";
	return os;
}
ostream& operator<<(ostream& os, const Piece* p)
{
	if ( p == nullptr )
		os << "[ ]";
	else if (p->get_color() == black)
		os << "[B]";
	else
		os << "[W]";

	return os;
}