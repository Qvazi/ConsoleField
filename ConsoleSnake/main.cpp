#include <iostream>
#include <ctime>
#include <list>
enum { WIDTH = 11 , HEIGHT = 8 };
enum Field { EMPTY,APPLE,SNAKE_BLOCK,BORDER};
Field f[WIDTH+2][HEIGHT+2];
typedef std::list<std::pair<int, int> > snakeBlock;
snakeBlock sBlock;
void draw(int w=1,int h=1);
void initField();
void drawField();
void newApple();
void setField(Field f,int x,int y);
Field blockField(int,int);
// Размеры поля



int main()
{
	srand(time(0));
	using std::cin;
	using std::cout;
	using std::endl;
	
	std::cout << "This is ConsoleSnake!" << std::endl;
	initField();
	newApple();
	sBlock.push_back(std::pair<int,int>(WIDTH/2+1,HEIGHT/2+1));
	char walk = ' ';
	do
	{
		std::pair<int,int> p = sBlock.front();
		
		switch(walk)
		{
		case 'w':
			p.second--;
			break;
		case 'a':
			p.first--;
			break;
		case 's':
			p.second++;
			break;
		case 'd':
			p.first++;
			break;
		}
		// Проверка на выход за пределы поля
		if(p.first < 1) p.first = 1;
		else if(p.first > WIDTH) p.first = WIDTH;
		if(p.second < 1) p.second = 1;
		else if(p.second > HEIGHT) p.second = HEIGHT;
		// Проверка на столкновение с яблоком
		
		sBlock.push_front(p);
		
		if (blockField(p.first, p.second) != APPLE)
		{
			setField(SNAKE_BLOCK, p.first, p.second);
			std::pair<int, int> p = sBlock.back();
			setField(EMPTY, p.first, p.second);
			sBlock.pop_back();
		}
		else
		{
			setField(SNAKE_BLOCK, p.first, p.second);
			newApple();
		}
		system("cls");
		drawField();
	}while(cin.get(walk) && walk != 'q');

	//draw(WIDTH,HEIGHT);

	std::cin.get();
	return 0;
}
void newApple()
{
	int x,y;
	do
	{
		x = rand() % WIDTH+1;
		y = rand() % HEIGHT+1;
	}
	while(blockField(x,y)!=EMPTY);
	setField(APPLE,x,y);
}
void setField(Field t,int x,int y)
{
	f[x][y] = t;
}
Field blockField(int w,int h)
{
	return f[w][h];
}
void initField()
{
	for(int h=0;h<HEIGHT+2;++h)
		for(int w=0;w<WIDTH+2;++w)
			if(w==0 || h==0 || w==(WIDTH+1) || h==(HEIGHT+1))
				f[w][h] = BORDER;
			else
				f[w][h] = EMPTY;
}
void drawField()
{
	// Отрисовка поля
	for (int y = 0; y < HEIGHT+2; ++y)
	{
		for (int x = 0; x < WIDTH+2; ++x)
		{
		  switch (f[x][y])
		  {
		  case EMPTY:
				std::cout << ' ';
		break;
		  case BORDER:
			  std::cout << '#';
			  break;
		  case SNAKE_BLOCK:
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
void draw(int _w,int _h)
{
	using std::cout;
	using std::endl;

	for(int h=0;h<=_h+1;++h)
	{
		for(int w=0;w<=_w+1;++w)
		{
			if(w==0 || h==0 || w==_w+1 || h==_h+1)
				cout << '#';
			else
				cout << ' ';
		}
		cout << endl;
	}
}