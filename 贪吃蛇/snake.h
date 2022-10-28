#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
typedef struct _set
{ //蛇的链表实现
    int x;
    int y;
} set;
typedef struct _food
{ //食物*
    int x;
    int y;
} food;
void creatasnake();
void showsnake();
void showfood();
