#define _CRT_SECURE_NO_WARNINGS
#define ROW 3
#define COL 3

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//�����ʼ��
void Initboard(char board[ROW][COL], int row, int col);//��ʼ����
void Displaybard(char board[ROW][COL], int row, int col);//��ӡ����

void Playermove(char board[ROW][COL], int row, int col);//�����
void Computermove(char board[ROW][COL], int row, int col);//������
char isWin(char board[ROW][COL], int row, int col);