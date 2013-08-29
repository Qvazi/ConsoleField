#pragma once
#ifndef _FIELD_HPP_
#define _FIELD_HPP_

class Snake;

class Field
{
public:
	enum { WIDTH = 20, HEIGHT = 15 };
	enum Unit { EMPTY,TDBORDER,LRBORDER,APPLE,SNAKE_BODY};
private:
	Unit f_[WIDTH+2][HEIGHT+2];
public:
	Field();
	void draw(const Snake & s);
	void newApple();
	Unit getUnit(int w,int h);
	void setUnit(Unit u,int w,int h);
};

#endif