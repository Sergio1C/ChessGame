#ifndef DESK_H
#define DESK_H
#include "Piece.h"
#include <vector>

template<int Size>
class Desk
{
public:
	int get_size() { return Size; };
	const Piece* piece(const Point&) const;
	void piece(const Point& adress, const Piece*);
	bool Is_Knight_Pos(const Point&) const; //проверяет какую фигуру ставить на клетку (true - Knight, false - Pawn)
private:
	const Piece* _desk[Size][Size];
};

template<int Size>
void Init(Desk<Size>& desk)
{
	int count = Size-1;
	//первые два ряда - белые фигуры
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			//пустые клетки
			if (i > 1)
				{
					desk.piece(Point(i, j), 0);
					continue;
				}

			if (desk.Is_Knight_Pos(Point(i, j)))
				desk.piece(Point(i, j), new Knight(white));
			else
				desk.piece(Point(i, j), new Pawn(white));
		}
	}
	//последние два ряда - черные фигуры
	for (int i = count; i > count - 2; i--)
	{
		for (int j = 0; j < Size; j++)
		{
			if (desk.Is_Knight_Pos(Point(i, j)))
				desk.piece(Point(i,j), new Knight(black));
			else
				desk.piece(Point(i, j), new Pawn(black));
		}			
	}
};

template<int Size>
const Piece* Desk<Size>::piece(const Point& p) const
{
	const Piece* ptr = 0;
	try
	{ 
		ptr = _desk[p.getX()][p.getY()];
	}
	catch (...) {}
	return ptr;
};

template<int Size>
void Desk<Size>::piece(const Point& p, const Piece* piece)
{
	_desk[p.getX()][p.getY()] = piece;
}

template<int Size>
bool Desk<Size>::Is_Knight_Pos(const Point& p) const
{	
	//начальные позиции фигуры типа Knight на доске 
	Point KnightPos[4] = { Point(0, 1), Point(0, 6), Point(7, 1), Point(7, 6) };

	for (int i = 0; i < 3; i++)
	{
		if (KnightPos[i].getX() == p.getX() && KnightPos[i].getY() == p.getY()) return true;
	}
	return false;
}

template<int Size>
std::ostream& operator<<(ostream& os, Desk<Size>& D)
{
	//x-coords [0...Size]
	os << "x|y";
	for (int x = 0; x < Size; x++)
	os <<" "<<x<<" ";
	os << endl;

	for (int x = 0; x < D.get_size(); x++)
	{
		os << x << " ";
		for (int j = 0; j < D.get_size(); j++)
		{			
			os << D.piece(Point(x, j));
		}
	
		os << endl;
	}
	return os;
}

#endif