#include <iostream>
#include <ctime>
#include <cstdlib>
#include "winFun.hpp"
#include "field.hpp"
#include "snake.hpp"


Field::Field()
{
	for(int h=0;h<HEIGHT;++h)
		for(int w=0;w<WIDTH;++w)
			f_[w][h] = EMPTY;
	newApple();
}
void Field::drawBorder() const
{

for(int h=0;h<HEIGHT+2;++h)
	{
		for(int w=0;w<WIDTH+2;++w)
		{
			if( h==0 || h==(HEIGHT+1) )
			{
				gotoxy(w,h);
				std::cout << '#';
			}
			else if( w==0 || w==(WIDTH+1) )
			{
				gotoxy(w,h);
				std::cout << '#';
			}
		}
		std::cout << std::endl;
	}
			
}
void Field::draw(const Snake & s)
{
	using std::cout;
	using std::endl;
	Point p = s.getBody().front();
	for (int y = 0; y < HEIGHT; ++y)
	{
		for (int x = 0; x < WIDTH; ++x)
		{
		  switch (f_[x][y])
		  {
		    case SNAKE_BODY:
			  if(x == p.w && y == p.h)
				  switch(s.getDirection())
				  {
				  case Snake::LEFT:
					  //std::cout << static_cast<char>(17);
					  gotoxy(x+1,y+1);
					  std::cout << '<';
					  break;
				  case Snake::RIGHT:
					  //std::cout << static_cast<char>(16);
					  gotoxy(x+1,y+1);
					  std::cout << '>';
					  break;
				  case Snake::DOWN:
					  //std::cout << static_cast<char>(31);
					  gotoxy(x+1,y+1);
					  std::cout << 'v';
					  break;
				  case Snake::UP:
					  //std::cout << static_cast<char>(30);
					  gotoxy(x+1,y+1);
					  std::cout << '^';
					  break;
				  }
			  else
			  {
				  gotoxy(x+1,y+1);
				  std::cout << '%';
			  }
				break;
		  case APPLE:
			//std::cout << char(3);
			  gotoxy(x+1,y+1);
			std::cout << '*';
		break;
		  case EMPTY:
			   gotoxy(x+1,y+1);
			std::cout << ' ';
			  break;
		  }
	  
		}
	}
}

void Field::newApple()
{
	std::srand(std::time(0));
	int w,h;
	do
	{
		w = std::rand() % WIDTH;
		h = std::rand() % HEIGHT;
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
