#include"menu.h"
extern int score;
extern char state;
void gamecreat()
{ //创建窗口 蛇
    system("cls");
    setpos(30, 5);
    for (int i = 1; i <= 32; i++)
        printf("=");
    setpos(30, 20);
    for (int i = 1; i <= 32; i++)
        printf("=");
    for (int i = 1; i <= 14; i++)
    {
        setpos(30, i + 5);
        printf("||\n");
    }
    for (int i = 1; i <= 14; i++)
    {
        setpos(60, i + 5);
        printf("||\n");
    }
    creatasnake();
    setpos(80, 10);
    printf("按上下左右键开始");
    setpos(30, 30);
    system("pause");
}
void menu()
{ //菜单栏
    setpos(30, 10);
    printf("新游戏\n");
	printf("                      通过上下左右键控制移动方向\n");
	printf("                            按下空格暂停\n");
	printf("                            按下Esc退出\n");
    setpos(25, 20);
    printf("按下任意键进入\n");
    setpos(25, 25);
    system("pause");
}
