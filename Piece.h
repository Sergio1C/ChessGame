#ifndef PIECE_H
#define PIECE_H
#include "Point.h"

enum Piece_color { black, white};
enum Piece_type {pawn,knight,kind};

class Piece
{

friend ostream& operator<<(ostream&, const Piece*);
friend ostream& operator<<(ostream&, const Piece&);

public:
	Piece(Piece_color color, Piece_type _type);
	virtual ~Piece() {}
	virtual bool chek_move(const Point& from, const Point& to) const = 0;
	Piece_color get_color() const;
private:
	Piece_color _color;
	Piece_type _type;
	virtual string print() const = 0;
};

class Pawn : public Piece
{
public:
	Pawn(Piece_color color);
	virtual bool chek_move(const Point& from, const Point& to) const;
	virtual string print() const;
};

class Knight : public Piece
{
public:
	Knight(Piece_color color);
	virtual bool chek_move(const Point& from, const Point& to) const;
	virtual string print() const;
};

class Kind : public Piece
{
public:	
	Kind(Piece_color color);
	virtual bool chek_move(const Point& from, const Point& to) const;
	virtual string print() const;
};

#endif