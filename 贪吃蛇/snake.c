#include"snake.h"
#include"pos.h"
food myfood;
set snake[40];
int tail = 1;
void showsnake()
{
    int i = 0; //在终端输出蛇的形状
    while (i <= tail)
    {
        setpos(snake[i].x, snake[i].y);
        printf("■");
        i++;
    }
}
void creatasnake()
{ //蛇的初始化
    snake[1].x = 33;
    snake[1].y = 8;
    snake[0].x = 34;
    snake[0].y = 8;
    tail = 1;
    showsnake();
}
void showfood()
{ //在终端输出蛇
    srand(time(0));
    int x = rand() % 28 + 32;
    int y = rand() % 14 + 6;
    while (1)
    {
        bool flag = true;
        for (int i = 0; i <= tail; i++)
        {
            if (snake[i].x == x && snake[i].y == y)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            break;
        }
        else
        {
            x = rand() % 28 + 32;
            y = rand() % 14 + 6;
        }
    }
    setpos(x, y);
    printf("*");
    myfood.x = x;
    myfood.y = y;
}
