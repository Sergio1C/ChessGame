#ifndef DESK_H
#define DESK_H
#include "Piece.h"
#include <vector>

//начальные позиции фигур - (изначально был вектор но не смог его обойти чтобы осуществить поиск точки) 
Point KnightPos[4] = { Point(0, 1), Point(0, 6), Point(7, 1), Point(7, 6) };

template<int Size>
class Desk
{
public:
	int get_size() { return Size; };
	const Piece& piece(const Point&) const;
	void piece(const Point&, Piece&);
	bool Knight_Pos(const Point&) const;
	bool correct_coords(int x, int y) const;
private:
	Piece* _desk[Size][Size];
};

template<int Size>
void Init(Desk<Size>& desk)
{
	int count = Size-1;
	//первые два ряда - белые фигуры
	for (int i = 0; i < 2; i++)   //CHESS_COLUMN
	{
		for (int j = 0; j < count; j++)
		{
			if (desk.Knight_Pos(Point(i, j)))
				desk.piece(Point(i, j), Knight(white));
			else
				desk.piece(Point(i, j), Pawn(white));
		}
	}
	//последние два ряда - черные фигуры
	for (int i = count; i > count - 2; i--)
	{
		for (int j = 0; j < count; j++)
		{
			if (desk.Knight_Pos(Point(i, j)))
				desk.piece(Point(i,j), Pawn(black));
			else
				desk.piece(Point(i, j), Pawn(black));
		}			
	}
};

template<int Size>
const Piece& Desk<Size>::piece(const Point& p) const
{
	return *_desk[p.getX()][p.getY()];
}	
template<int Size>
void Desk<Size>::piece(const Point& p, Piece& piece)
{
	_desk[p.getX()][p.getY()] = &piece;
}

template<int Size>
bool Desk<Size>::Knight_Pos(const Point& p) const
{
	for (int i = 0; i < 3; i++)
	{
		//if (KnightPos[i] == p) return true; //
		if (KnightPos[i].getX() == p.getX() && KnightPos[i].getY() == p.getY()) return true;
	}
	return false;
}

template<int Size>
bool Desk<Size>::correct_coords(int x, int y) const
{
	//пока не нужна...
}

template<int Size>
std::ostream& operator<<(ostream& os, Desk<Size>& D)
{
	for (int i = 0; i < D.get_size(); i++)
	{
		for (int j = 0; j < D.get_size(); j++)
		{			
			os << D.piece(Point(i, j));
		}
	
		os << endl;
	}
	return os;
}

#endif