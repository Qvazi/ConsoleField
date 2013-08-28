#include <iostream>
#include <ctime>
enum { WIDTH = 11 , HEIGHT = 8 };
enum Field { EMPTY,APPLE,SNAKE_BLOCK,BORDER};
Field f[WIDTH+2][HEIGHT+2];

void draw(int w=1,int h=1);
void initField();
void drawField();
void newApple();
void setField(Field f,int x,int y);
Field isEmptyField(int,int);
// Размеры поля



int main()
{
	srand(time(0));
	using std::cin;
	using std::cout;
	using std::endl;
	
	std::cout << "This is ConsoleSnake!" << std::endl;
	initField();



	while(cin.get())
	{
		system("cls");
		newApple();
		drawField();
	}

	
	

	
	





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
	while(isEmptyField(x,y)!=EMPTY);
	setField(APPLE,x,y);
}
void setField(Field t,int x,int y)
{
	f[x][y] = t;
}
Field isEmptyField(int w,int h)
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