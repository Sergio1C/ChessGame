#include "Piece.h"

Piece::Piece(Piece_color color, Piece_type type) : _color(color), _type(type)
{}

Piece_color Piece::get_color() const
{
	return _color;
}

Pawn::Pawn(Piece_color color):Piece(color, pawn){}

bool Pawn::chek_move(const Point& from, const Point& to) const
{
	int row_from = from.getX();
	int col_from = from.getY();
	int row_to = to.getX();
	int col_to = to.getY();
	//пусть пешка всегда ходит на одну клетку и только вертикально
	if (col_from != col_to) return false;
	if (abs(row_from - row_to) != 1) return false;
	return true;
}

string Pawn::print() const
{
	string pic;
	pic = (get_color() == white ? "(" : "[");
	pic += "P";
	pic += (get_color() == white ? ")" : "]");
	return pic;
}

Knight::Knight(Piece_color color):Piece(color, knight){}

bool Knight::chek_move(const Point& from, const Point& to) const
{
	int x_from = from.getX();
	int y_from = from.getY();
	int x_to = to.getX();
	int y_to = to.getY();
	//возможные смещения по "y"=2 и по "x"=2 или наоборот храним в массиве xy[8]
	int dy = y_to - y_from;
	int dx = x_to - x_from;
	
	 const Point dPoint(dx, dy);
	       Point xy[8] = { Point(2, 1), Point(1, 2), Point(-1, 2), Point(-2, -1), Point(-2, -1), Point(-1, -2), Point(1, -2), Point(2, -1) };

	//проверим смещение 
	for (int i = 0; i < 8; i++)
	{
		if (xy[i] == dPoint) return true;
	}
	return false;
}

string Knight::print() const
{
	string pic;
	pic = (get_color() == white ? "(" : "[");
	pic += "k";
	pic += (get_color() == white ? ")" : "]");
	return pic;
}

Kind::Kind(Piece_color color):Piece(color, kind){}

bool Kind::chek_move(const Point& from, const Point& to) const
{
	int x_from = from.getX();
	int y_from = from.getY();
	int x_to = to.getX();
	int y_to = to.getY();
	int dy = y_to - y_from;
	int dx = x_to - x_from;

	return (abs(dy) < 2 || abs(dx) < 2);

}

string Kind::print() const
{
	string pic;
	pic = (get_color() == white ? "(" : "[");
	pic += "K";
	pic += (get_color() == white ? ")" : "]");
	return pic;
}

ostream& operator<<(ostream& os, const Piece* p)
{
	if (p == 0)
		os << "[ ]";
	else
		os << p->print().c_str();
	return os;
}

ostream& operator<<(ostream& os, const Piece& p)
{
	os << p.print().c_str();
	return os;
}