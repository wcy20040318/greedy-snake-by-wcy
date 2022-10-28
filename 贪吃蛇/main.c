#include<stdio.h>
#include"pos.h"
#include"move.h"
#include"menu.h"
#include"snake.h"
int main()
{

    hidepos();  //隐藏光标
    menu();//显示菜单
ret: //与goto对应 用于重启游戏
    gamecreat();//创建游戏界面,初始化数据，并暂停
    showfood();//创建食物 食物不能与蛇身重合
    snakemove();//通过按键控制蛇的移动 
    setpos(30, 25);
    printf("按下回车键准备再来一次\n");
    getchar();//读入回车
    goto ret;
    return 0;
}
