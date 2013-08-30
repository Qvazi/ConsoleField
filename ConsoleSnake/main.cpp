#define WINDOWS
#include <iostream>
#include <string>
#ifdef WINDOWS
#include <conio.h>
#include <Windows.h>
#else
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#endif
#include "game.hpp"
#ifdef WINDOWS
#define Speed(x) Sleep(x);
#endif

#ifndef WINDOWS
#define STDIN_FILENO 0
#define NB_DISABLE 0
#define NB_ENABLE 1

#define Speed(x) usleep(x*1000)

int _kbhit() {
  struct timeval tv;
  fd_set fds;
  tv.tv_sec = 0;
  tv.tv_usec = 0;
  FD_ZERO(&fds);
  FD_SET(STDIN_FILENO, &fds);
  select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
  return FD_ISSET(STDIN_FILENO, &fds);
}

void nonblock(int state) {
  struct termios ttystate;

  // Get the terminal state.
  tcgetattr(STDIN_FILENO, &ttystate);

  if (state == NB_ENABLE) {
    // Turn off canonical mode.
    ttystate.c_lflag &= ~ICANON;
    // Minimum of number input read.
    ttystate.c_cc[VMIN] = 1;
  } else if (state == NB_DISABLE) {
    // Turn on canonical mode.
    ttystate.c_lflag |= ICANON;
  }
  // Set the terminal attributes.
  tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
}

int _getch() {
  return fgetc(stdin);
}

#endif



Game game;

int speed = 200;

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
	using std::cout;
	using std::endl;
	using std::cin;
	using std::string;
		
#ifndef WINDOWS
  nonblock(NB_ENABLE);
#endif
	while(true)
	{
		if(_kbhit()) keyEvent();
		
		if(Game::PAUSE)
			continue;
			
			game.update();
#ifdef WINDOWS
			system("cls");
#else
			system("clear");
#endif			
			game.draw();

			cout << "Press 'p' to pause." << endl;
			cout << "Press 'u' to On\\Off sound." << endl;
			Speed(game.getSpeedGame());
			
	}
	
	return 0;
}
