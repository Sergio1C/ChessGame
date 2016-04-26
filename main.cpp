#include "Game.h"

int main()
{

	Desk<8> board;
	Init(board);

	cout << board;

	_getch();
	return 0;
}