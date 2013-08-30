#include <iostream>
#include <ctime>
#include <cstdlib>
#include "field.hpp"
#include "snake.hpp"

Field::Field()
{
	for(int h=0;h<HEIGHT+2;++h)
		for(int w=0;w<WIDTH+2;++w)
			if( h==0 || h==(HEIGHT+1) )
				f_[w][h] = TDBORDER;
			else if( w==0 || w==(WIDTH+1) )
				f_[w][h] = LRBORDER;
			else
				f_[w][h] = EMPTY;
	newApple();
}
void Field::draw(const Snake & s)
{
	using std::cout;
	using std::endl;
	Point p = s.getBody().front();
	for (int y = 0; y < HEIGHT+2; ++y)
	{
		for (int x = 0; x < WIDTH+2; ++x)
		{
		  switch (f_[x][y])
		  {
		  case EMPTY:
				std::cout << ' ';
		break;
		  case TDBORDER:
			  //std::cout << static_cast<char>(219);
			  std::cout << '#';
			  break;
		  case LRBORDER:
			  //std::cout << static_cast<char>(219);
			  std::cout << '#';			  
			  break;
		  case SNAKE_BODY:
			  if(x == p.w && y == p.h)
				  switch(s.getDirection())
				  {
				  case Snake::LEFT:
					  //std::cout << static_cast<char>(17);
					  std::cout << '<';
					  break;
				  case Snake::RIGHT:
					  //std::cout << static_cast<char>(16);
					  std::cout << '>';
					  break;
				  case Snake::DOWN:
					  //std::cout << static_cast<char>(31);
					  std::cout << 'v';
					  break;
				  case Snake::UP:
					  //std::cout << static_cast<char>(30);
					  std::cout << '^';
					  break;
				  }
			  else
				  std::cout << '%';
		break;
		  case APPLE:
			//std::cout << char(3);
			std::cout << '*';
		break;
		  }
	  
		}
		std::cout << std::endl;
	}
}

void Field::newApple()
{
	std::srand(std::time(0));
	int w,h;
	do
	{
		w = std::rand() % WIDTH+1;
		h = std::rand() % HEIGHT+1;
	}
	while(getUnit(w,h)!=EMPTY);
	setUnit(APPLE,w,h);
}

void Field::setUnit(Unit u,int w,int h)
{
	f_[w][h] = u;
}

Field::Unit Field::getUnit(int w,int h)
{
	return f_[w][h];
}
