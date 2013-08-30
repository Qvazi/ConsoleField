#include "winFun.hpp"


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //дескриптор консоли
void gotoxy(int x, int y){
    COORD position = {x,   y};
    SetConsoleCursorPosition(hConsole, position);
}

void hideCursor(){
   
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hConsole,&structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo( hConsole, &structCursorInfo );
}