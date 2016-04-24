#ifndef PIECE_H
#define PIECE_H
#include "Point.h"

enum Piece_color { black, white};

class Piece
{
public:
	Piece(Piece_color color);
	bool virtual chek_move(const Point& from, const Point& to) const =0;
	Piece_color get_color() const;
private:
	Piece_color _color;
};

//пешка
class Pawn : public Piece
{
public:
	Pawn(Piece_color color);
	bool chek_move(const Point& from, const Point& to) const;
};
//конь
class Knight : public Piece
{
public:
	Knight(Piece_color color);
	bool chek_move(const Point& from, const Point& to) const;
};

#endif