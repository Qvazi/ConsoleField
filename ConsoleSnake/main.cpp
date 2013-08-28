#include <iostream>
void draw(int w=1,int h=1);
// Размеры поля
enum { WIDTH = 15 , HEIGHT = 9 };

int main()
{
	
	std::cout << "This is ConsoleSnake!" << std::endl;

	draw(WIDTH,HEIGHT);

	std::cin.get();
	return 0;
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