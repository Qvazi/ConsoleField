#include <ctime>
#include "snake.hpp"
#include "field.hpp"

Snake::Snake()
{
	srand(time(0));
	direction = static_cast<Direction>(rand() % 4);
	lastMove = direction;
	body.push_back(Point(Field::WIDTH/2+1,Field::HEIGHT/2+1));

}