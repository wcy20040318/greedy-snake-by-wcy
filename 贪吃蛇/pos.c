#pragma once
#include "pos.h"
void hidepos()
{
    CONSOLE_CURSOR_INFO cur;
    HANDLE myhandle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(myhandle, &cur);
    cur.bVisible = 0;
    SetConsoleCursorInfo(myhandle, &cur);
}
void setpos(int x, int y)
{ //将光标移到x，y
    COORD pos;
    pos.X = x;
    pos.Y = y;
    HANDLE myoutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(myoutput, pos);
}
