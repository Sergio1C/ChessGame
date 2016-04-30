#include "Game.h"

//main menu
void menu()
{
	int choose;
	while (true)
	{
		cout << "Enter the game type:(chess=0;barley=1;exit=2)";
		cin >> choose;
		switch (choose)
		{
		case 0: {ChessGame(); break; }
		case 1: {cout<<"not do"; break; }
		case 2: {exit(0);	   }
		default: {
					cout << endl;
					continue;
				 }
		}
	}
}

int main()
{
	menu();

	_getch();
	return 0;
}
