#pragma once
#ifndef _SNAKE_HPP_
#define _SNAKE_HPP_
#include <list>
#include "field.hpp"
class Game;
class Point
{
public:
	int w,h;
	Point(int w_ = 0,int h_ = 0):w(w_),h(h_){}
};

class Snake
{
public:
	enum Direction { UP, DOWN, LEFT, RIGHT };
private:
	typedef std::list<Point> Body;
	Body body;
	Direction direction;
	Direction lastMove;
public:
	Snake();
	const Body & getBody() const;
	void keyEvent(Direction d);
	bool update(Game & game);
	const Direction & getDirection() const;
};

#endif