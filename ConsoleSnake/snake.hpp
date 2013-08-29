#pragma once
#ifndef _SNAKE_HPP_
#define _SNAKE_HPP_
#include <list>
#include "field.hpp"
class Score;

class Point
{
public:
	int w,h;
	Point(int w_ = 1,int h_ = 1):w(w_),h(h_){}
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
	bool update(Field & field,Score & score);
	const Direction & getDirection() const;
};

#endif