#include "Point.h"

Point::Point(int x, int y): _x(x), _y(y) {}

int Point::getX() const
{
	return _x;
}

int Point::getY() const
{
	return _y;
}

void Point::SetX(int new_x)
{
	_x = new_x;
}

void Point::SetY(int new_x)
{
   _y = new_x;
}

void Point::move(int dx, int dy)
{
	_x +=dx;
	_y += dy;
}

std::ostream& operator<<(std::ostream& os, const Point& p)
{
	os << "x=" << p.getX() << "y=" << p.getY() << std::endl;
	return os;
}

bool operator==(const Point& p1, const Point& p2)
{
	return (p1.getX() == p2.getX()) && (p1.getY() == p2.getY());
}