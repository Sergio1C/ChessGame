#ifndef PIECE_H
#define PIECE_H
#include "Point.h"
#include <typeinfo.h>

enum Piece_color { black, white};

class Piece
{
public:
	Piece(Piece_color color);
	bool virtual chek_move(const Point& from, const Point& to) const =0;
	Piece_color get_color() const;
    string virtual print() const=0;
private:
	Piece_color _color;
	friend ostream& operator<<(ostream&, Piece&);
};

//пешка
class Pawn : public Piece
{
public:
	Pawn(Piece_color color);
	bool chek_move(const Point& from, const Point& to) const;
	string print() { return "[P]"; }
};
//конь
class Knight : public Piece
{
public:
	Knight(Piece_color color);
	bool chek_move(const Point& from, const Point& to) const;
	string print() { return "[K]"; }
};

ostream& operator<<(ostream& os, const Piece& p);
ostream& operator<<(ostream& os, const Piece* p);
ostream& operator<<(ostream& os, const Pawn& p);
ostream& operator<<(ostream& os, const Knight& p);

#endif