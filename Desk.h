#ifndef DESK_H
#define DESK_H
#include "Piece.h"
#include <vector>

template<int Size>
class Desk
{
public:
	Desk();
	~Desk();
	int size() const { return Size; };
	const Piece* piece(const Point& adress) const;
	void piece(const Point& adress, const Piece*);
	void delete_piece(const Point& adress);
private:
	const Piece* _desk[Size][Size];
};

template<int Size>
Desk<Size>::Desk()
{
	for (int x = 0; x < Size; x++)
	{
		for (int y = 0; y < Size; y++)
		{
			delete_piece(Point(x, y));
		}
	}
}

template<int Size>
Desk<Size>::~Desk()
{
	for (int x = 0; x < Size; x++)
	{
		for (int y = 0; y < Size; y++)
		{
			delete _desk[x][y];
		}
	}
}

template<int Size>
void Erase(Desk<Size>& desk)
{

}

template<int Size>
const Piece* Desk<Size>::piece(const Point& p) const
{
	if (p.getX() > Size || p.getY() > Size || p.getX() < 0 || p.getY() < 0)
	{
		throw std::runtime_error("Error:your position is out of desk range"); //компилятор говорит необработанное исключение
	}

    return _desk[p.getX()][p.getY()];
	
};

template<int Size>
void Desk<Size>::piece(const Point& p, const Piece* piece)
{
	_desk[p.getX()][p.getY()] = piece;
}

template <int Size>
void Desk<Size>::delete_piece(const Point& p)
{
	_desk[p.getX()][p.getY()] = nullptr;
}

template<int Size>
std::ostream& operator<<(ostream& os, const Desk<Size>& D)
{
	//x-coords [0...Size]
	os << "x|y";
	for (int x = 0; x < Size; x++)
	os <<" "<<x<<" ";
	os << endl;

	for (int x = 0; x < D.size(); x++)
	{
		os << x << " ";
		for (int j = 0; j < D.size(); j++)
		{			
			os << D.piece(Point(x, j));
		}
	
		os << endl;
	}
	return os;
}

#endif