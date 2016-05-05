#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <conio.h>
#include <sstream>

using namespace std;

class Point
{
public:
	Point(int x = 0, int y = 0);
	int getX() const;
	int getY() const;
	void SetX(int new_x);
	void SetY(int new_y);	
	void move(int dx, int dy);
private:
	int _x;
	int _y;
};

std::ostream& operator<<(std::ostream& os, const Point& p);

bool operator==(const Point& p1, const Point& p2);

istream& operator>>(istream& is, Point&);

#endif