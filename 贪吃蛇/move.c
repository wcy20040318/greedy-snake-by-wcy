#include "move.h"
#include"snake.h"
#include"pos.h"
#define upwall 5
#define downwall 20
#define leftwall 31
#define rightwall 60
int score = 0;
char state = 'P';
extern set snake[40];
extern int tail;
extern food myfood;
void movestate()
{ //获取用户输入，存储或改变运动状态，同时不能在上升时向下运动
    if (GetAsyncKeyState(VK_UP) && state != 'S')
    {
        state = 'W';
    }
    else if (GetAsyncKeyState(VK_DOWN) && state != 'W')
    { // WSAD对应上下左右
        state = 'S';
    }
    else if (GetAsyncKeyState(VK_RIGHT) && state != 'A')
    {
        state = 'D';
    }
    else if (GetAsyncKeyState(VK_LEFT) && state != 'D')
    {
        state = 'A';
    }
    else if (GetAsyncKeyState(VK_SPACE))
    {
        state = 'P';
    }
	else if (GetAsyncKeyState(VK_ESCAPE)){
		exit(0);
	}
}
void snakemove()
{
	score = 0;
	bool eat = true;
	bool endgame = true;
	state = 'P';
    while (endgame)
    {
		if(eat){
			setpos(80,15);
			printf("你的当前分数是: %d",score);
			setpos(80,18);
			printf("最高得分是: %d",maxscore(score));
		}
        movestate();
        if (state == 'W')
        {
            Sleep(200); //控制速度
            if (snake[0].y == myfood.y && snake[0].x == myfood.x)
            { //前方有食物
                eat = true;
                score++;
                showfood(); //重新输出食物
            }
            else if (snake[0].y == upwall || snake[0].y == downwall || snake[0].x == leftwall || snake[0].x == rightwall)
            {
                endgame = false; //撞墙游戏结束
            }
            else
            {
                int x = snake[tail].x, y = snake[tail].y;
                for (int i = tail; i >= 1; i--)
                {
                    snake[i].x = snake[i - 1].x;
                    snake[i].y = snake[i - 1].y;
                }
                snake[0].y--;
                setpos(x, y);
                printf(" ");
                if (eat)
                {
                    snake[++tail].x = x;
                    snake[tail].y = y;
                    eat = false;
                }
            }
        }
        if (state == 'S')
        {
            Sleep(200);
            if (snake[0].y == myfood.y && snake[0].x == myfood.x)
            { //前方有食物
                eat = true;
                score ++;
                showfood(); //吃了之后消化一下，重新输出食物
            }
            else if (snake[0].y == upwall || snake[0].y == downwall || snake[0].x == leftwall || snake[0].x == rightwall)
            {
                endgame = false; //撞墙游戏结束
            }
            else
            { //正常前进，因为每次循环都会调用递归，所以递归肯定不是最优解
                int x = snake[tail].x, y = snake[tail].y;
                for (int i = tail; i >= 1; i--)
                {
                    snake[i].x = snake[i - 1].x;
                    snake[i].y = snake[i - 1].y;
                }
                snake[0].y++;
                setpos(x, y);
                printf(" ");
                if (eat)
                {
                    snake[++tail].x = x;
                    snake[tail].y = y;
                    eat = false;
                }
            }
        }
        if (state == 'D')
        {
            Sleep(200);
            if (snake[0].y == myfood.y && snake[0].x == myfood.x)
            { //前方有食物
                eat = true;
                score ++;
                showfood(); //重新输出食物
            }
            else if (snake[0].y == upwall || snake[0].y == downwall || snake[0].x == leftwall || snake[0].x == rightwall)
            {
                endgame = false; //撞墙游戏结束
            }
            else
            { //正常前进，因为每次循环都会调用递归，所以递归肯定不是最优解
                int x = snake[tail].x, y = snake[tail].y;
                for (int i = tail; i >= 1; i--)
                {
                    snake[i].x = snake[i - 1].x;
                    snake[i].y = snake[i - 1].y;
                }
                snake[0].x++;
                setpos(x, y);
                printf(" ");
                if (eat)
                {
                    snake[++tail].x = x;
                    snake[tail].y = y;
                    eat = false;
                }
            }
        }
        if (state == 'A')
        {
            Sleep(200);
            if (snake[0].y == myfood.y && snake[0].x == myfood.x)
            { //前方有食物
                eat = true;
                score ++;
                showfood(); //重新输出食物
            }
            else if (snake[0].y == upwall || snake[0].y == downwall || snake[0].x == leftwall || snake[0].x == rightwall)
            {
                endgame = false; //撞墙游戏结束
            }
            else
            { //正常前进，因为每次循环都会调用递归，所以递归肯定不是最优解
                int x = snake[tail].x, y = snake[tail].y;
                for (int i = tail; i >= 1; i--)
                {
                    snake[i].x = snake[i - 1].x;
                    snake[i].y = snake[i - 1].y;
                }
                snake[0].x--;
                setpos(x, y);
                printf(" ");
                if (eat)
                {
                    snake[++tail].x = x;
                    snake[tail].y = y;
                    eat = false;
                }
            }
        }
        if (state == 'P')
        {
            setpos(30, 30);
            system("pause");
        }
        showsnake();

    }
}
