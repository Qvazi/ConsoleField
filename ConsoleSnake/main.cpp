#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include "game.hpp"
#define Speed(x) Sleep(x);
Game game;

void keyEvent()
{
	char key = _getch();
	switch(key)
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
		default: break;
		}
}

int main()
{
	using std::cout;
	using std::endl;
	using std::cin;
	using std::string;
		
	while(true)
	{
		if(_kbhit()) keyEvent();
		
		game.update();
		system("cls");
		game.draw();
		Speed(game.getSpeedGame());
		
	}
	
	return 0;
}