#include <ctime>
#include <cstdlib>
#include <iostream>
#include "snake.hpp"
#include "winFun.hpp"
#include "field.hpp"
#include "game.hpp"
Snake::Snake()
{
	std::srand(std::time(0));
	direction = static_cast<Direction>(std::rand() % 4);
	lastMove = direction;
	body.push_back(Point(Field::WIDTH/2+1,Field::HEIGHT/2+1));
}
void Snake::keyEvent(Direction d)
{
	if(Game::PAUSE)
		return;
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
bool Snake::update(Game & game)
{
	if(Game::PAUSE)
		return true;
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
	if(game.getDiffuculty() == Game::EASY)
	{
		if(p.w < 0)
			p.w = Field::WIDTH-1;
		else if(p.w > Field::WIDTH-1)
			p.w = 0;
		if(p.h < 0)
			p.h = Field::HEIGHT-1;
		else if(p.h > Field::HEIGHT-1)
			p.h = 0;
		
	}
	else
	{
		if(p.w < 0 || p.w > Field::WIDTH-1 || p.h < 0 || p.h > Field::HEIGHT-1)
		{
			if(Game::SOUND)
				std::cout << "\a\a\a";
			return false;
		}
	}
	if (game.getField().getUnit(p.w, p.h) == Field::SNAKE_BODY)
	{
		if(Game::SOUND)
			std::cout << "\a\a\a";
		return false;
	}

	body.push_front(p);

	if(game.getField().getUnit(p.w,p.h) == Field::APPLE)
	{
		if(Game::SOUND)
			std::cout << "\a";
		// ѕлюсуем €блоко к очкам
		game.getScore().plusApple();

		game.getField().setUnit(Field::SNAKE_BODY,p.w,p.h);
		game.getField().newApple();
	}
	else
	{
		game.getField().setUnit(Field::SNAKE_BODY,p.w,p.h);
		Point p = body.back();
		game.getField().setUnit(Field::EMPTY,p.w,p.h);
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
