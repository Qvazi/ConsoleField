#include <iostream>
#include "game.hpp"
Game game;

int main()
{
	using std::cout;
	using std::endl;
	using std::cin;

	cout << "Hello, GitHub!" << endl;
	
	game.draw();

	cout << "Press any key to quit...";
	cin.get();
	return 0;
}