#include <ctime>
#include "snake.hpp"
#include "field.hpp"
#include "game.hpp"
Snake::Snake()
{
	srand(time(0));
	direction = static_cast<Direction>(rand() % 4);
	lastMove = direction;
	body.push_back(Point(Field::WIDTH/2+1,Field::HEIGHT/2+1));
}
void Snake::keyEvent(Direction d)
{
	if (d == direction)
	 return;
	  switch (d)
	  {
	  case LEFT:
		  if (lastMove == RIGHT)
		  return;
		break;
	  case UP:
		if (lastMove == DOWN)
		  return;
		break;
	  case RIGHT:
		if (lastMove == LEFT)
		  return;
		break;
	  case DOWN:
		if (lastMove == UP)
		  return;
		break;
	  }
  direction = d;
}
bool Snake::update(Field & f,Score & score)
{
	lastMove = direction;
	Point p = body.front();
	switch(direction)
	{
	case UP:
		p.h--;
		break;
	case DOWN:
		p.h++;
		break;
	case LEFT:
		p.w--;
		break;
	case RIGHT:
		p.w++;
		break;
	}
	if(p.w < 1 || p.w > Field::WIDTH || p.h < 1 || p.h > Field::HEIGHT)
		return false;

	if (f.getUnit(p.w, p.h) == Field::SNAKE_BODY)
    return false;

	body.push_front(p);

	if(f.getUnit(p.w,p.h) == Field::APPLE)
	{
		score.plusApple();
		f.setUnit(Field::SNAKE_BODY,p.w,p.h);
		f.newApple();
	}
	else
	{
		f.setUnit(Field::SNAKE_BODY,p.w,p.h);
		Point p = body.back();
		f.setUnit(Field::EMPTY,p.w,p.h);
		body.pop_back();
	}
	if(body.size() >= Field::WIDTH * Field::HEIGHT -1)
		return false;
	return true;
}
const Snake::Body & Snake::getBody() const
{
	return body;
}
const Snake::Direction & Snake::getDirection() const
{
	return direction;
}