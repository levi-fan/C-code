#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void Initboard(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}
void Displaybard(char board[ROW][COL], int row, int col) 
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ",board[i][j]);
			if (j < col - 1) {
				printf("|");
			}
		}printf("\n");
		if (i < row-1) 
		{
			for (int j = 0; j< col; j++) 
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}printf("\n");
		
		}
	}printf("\n");
}
void Playermove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("玩家走->");
	while (1) {
		scanf("%d%d", &x, &y);
		if ((x >= 1 && x <= row) && (y >= 1 && y <= col)) {

			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;

			}
			else
			{
				printf("该坐标被占用！\n");
			}
		}
		else
		{
			printf("输入不合法！请重新输入！\n");
		}
	}
}
void Computermove(char board[ROW][COL], int row, int col)
{
	printf("游戏走->\n");
	while (1) {

		int x = rand() % 3;
		int y = rand() % 3;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#'; break;
		}
	}
	
}
char isWin(char board[ROW][COL], int row, int col)
{
	int flag = 1;//假设是平局
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				flag=0;//不是平局
			}
		}
	}if (flag == 1)
	{
		return 'Q';
	}

	for (int i = 0; i < row; i++)//判断每一行是否相等
	{
		if ((board[i][0] == board[i][1])&&(board[i][1] == board[i][2]))
		{
			return board[i][0];
		}
	}
	for (int i = 0; i <col; i++)//判断每一列是否相等
	{
		if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]))
		{
			return board[0][i];
		}
	}//判断对角线是否相等
	if ((board[0][0] == board[1][1]) && (board[1][1]) == board[2][2])
	{
		return board[0][0];
	}
	if ((board[0][2] == board[1][1]) && (board[1][1]) == board[2][0])
	{
		return board[0][0];
	}
	

}


