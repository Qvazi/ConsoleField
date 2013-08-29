#include <iostream>
#include <ctime>
#include "field.hpp"

Field::Field()
{
	for(int h=0;h<HEIGHT+2;++h)
		for(int w=0;w<WIDTH+2;++w)
			if(w==0 || h==0 || w==(WIDTH+1) || h==(HEIGHT+1))
				f_[w][h] = BORDER;
			else
				f_[w][h] = EMPTY;
	newApple();
}
void Field::draw()
{
	using std::cout;
	using std::endl;

	for (int y = 0; y < HEIGHT+2; ++y)
	{
		for (int x = 0; x < WIDTH+2; ++x)
		{
		  switch (f_[x][y])
		  {
		  case EMPTY:
				std::cout << ' ';
		break;
		  case BORDER:
			  std::cout << '#';
			  break;
		  case SNAKE_BODY:
			std::cout << '+';
		break;
		  case APPLE:
			std::cout << '@';
		break;
		  }
	  
		}
		std::cout << std::endl;
	}
}

void Field::newApple()
{
	srand(time(0));
	int w,h;
	do
	{
		w = rand() % WIDTH+1;
		h = rand() % HEIGHT+1;
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
