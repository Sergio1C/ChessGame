#include "Game.h"

//main menu
void menu()
{
	int choose;
	while (true)
	{
		cout << "Choose the game type:(chess=0;barley=1;exit=2)";
		cin >> choose;
		switch (choose)
		{
		case 0: {Game(static_cast<Game_type>(choose)); break; }
		case 1: {Game(static_cast<Game_type>(choose)); break; }
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
