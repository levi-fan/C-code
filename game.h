#define _CRT_SECURE_NO_WARNINGS
#define ROW 3
#define COL 3

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//数组初始化
void Initboard(char board[ROW][COL], int row, int col);//初始棋盘
void Displaybard(char board[ROW][COL], int row, int col);//打印棋盘

void Playermove(char board[ROW][COL], int row, int col);//玩家走
void Computermove(char board[ROW][COL], int row, int col);//电脑走
char isWin(char board[ROW][COL], int row, int col);