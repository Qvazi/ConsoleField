#include <iostream>
#include <string>
#include "game.hpp"
Game game;

void keyEvent(std::string & key)
{
	switch(key[0])
		{
		case 'w':
			game.keyEvent(Snake::UP);
			break;
		case 's':
			game.keyEvent(Snake::DOWN);
			break;
		case 'd':
			game.keyEvent(Snake::RIGHT);
			break;
		case 'a':
			game.keyEvent(Snake::LEFT);
			break;
		}
}

int main()
{
	using std::cout;
	using std::endl;
	using std::cin;
	using std::string;

	cout << "Hello, GitHub!" << endl;
	string key;
	
	do
	{
		system("cls");
		keyEvent(key);
		game.update();
		game.draw();
				
	
	} while ( getline(cin,key) && key != "q");
	
	cout << "Press any key to quit...";
	cin.get();
	return 0;
}