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
		case 'u':
			Game::SOUND = !Game::SOUND;
			break;
		case 'p':
			Game::PAUSE = !Game::PAUSE;
			break;
		default: break;
		}
	
}

int main()
{
	system("title ConsoleSnake.");
	using std::cout;
	using std::endl;
	using std::cin;
	using std::string;
		
	while(true)
	{
		if(_kbhit()) keyEvent();
		
		if(Game::PAUSE)
			continue;
			game.update();
			system("cls");			
			game.draw();
			cout << "Press 'p' to pause." << endl;
			cout << "Press 'u' to On\\Off sound." << endl;
			Speed(game.getSpeedGame());
		
		
	}
	
	return 0;
}