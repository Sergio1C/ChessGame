#ifndef PIECE_H
#define PIECE_H
#include "Point.h"
#include <typeinfo.h>

enum Piece_color { black, white};
enum Piece_type {pawn,knight};

class Piece
{
public:
	Piece(Piece_color color, Piece_type type);
	bool virtual chek_move(const Point& from, const Point& to) const =0;
	Piece_color get_color() const { return _color; }
	Piece_type get_type() const { return _type; }
private:
	Piece_color _color;
	Piece_type _type;
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

ostream& operator<<(ostream& os, const Piece& p);
ostream& operator<<(ostream& os, const Pawn& p);
ostream& operator<<(ostream& os, const Knight& p);

#endif