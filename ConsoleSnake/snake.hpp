#ifndef _SNAKE_HPP_
#define _SNAKE_HPP_
#include <list>

class Point
{
private:
	int w,h;
public:
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
};

#endif