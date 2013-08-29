#ifndef _FIELD_HPP_
#define _FIELD_HPP_

class Field
{
public:
	enum { WIDTH = 15, HEIGHT = 10 };
	enum Unit { EMPTY,BORDER,APPLE,SNAKE_BODY};
private:
	Unit f_[WIDTH+2][HEIGHT+2];
public:
	Field();
	void draw();
	void newApple();
};

#endif