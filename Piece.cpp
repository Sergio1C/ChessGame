#include "Piece.h"

Piece::Piece(Piece_color color, Piece_type type) : _color(color), _type(type)
{
}

//Pawn
Pawn::Pawn(Piece_color color):Piece(color,pawn)
{
}

bool Pawn::chek_move(const Point& from, const Point& to) const
{
	int x_from = from.getX();
	int y_from = from.getY();
	int x_to = to.getX();
	int y_to = to.getX();
	//����� ����� ������ ����� �� ���� Point � ������ �����������
	if (x_from != x_to) return false;
	if (abs(y_to - y_from) !=1) return false;
	return true;
}

//Knight
Knight::Knight(Piece_color color):Piece(color, knight)
{
}

bool Knight::chek_move(const Point& from, const Point& to) const
{
	int x_from = from.getX();
	int y_from = from.getY();
	int x_to = to.getX();
	int y_to = to.getX();
	//��������� �������� �� "y"=2 � �� "x"=2 ��� �������� ������ � ������� xy[8]
	int dy = y_to - y_from;
	int dx = x_to - x_from;
	
	 Point dPoint(dx, dy);
	 Point xy[8] = { Point(2, 1), Point(1, 2), Point(-1, 2), Point(-2, -1), Point(-2, -1), Point(-1, -2), Point(1, -2), Point(2, -1) };

	//�������� �������� 
	for (int i = 0; i < 8; i++)
	{
		//if (xy[i] == dPoint) return true;
	}
	return false;
}

ostream& operator<<(ostream& os, const Piece& p)
{
	Piece_type p_type = p.get_type();

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