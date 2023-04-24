#define _CRT_SECURE_NO_WARNINGS
#include"game.h" 
void menu() {
	printf("###################\n");
	printf("##1.play   0.exit    ####\n");
	printf("###################\n");


}
void game()
{
	char board[ROW][COL] = { 0 };
	Initboard(board, ROW, COL);
	Displaybard(board, ROW, COL);
	while (1) {
		Playermove(board, ROW, COL);
		Displaybard(board, ROW, COL);
		if (isWin(board, ROW, COL) == '*')
		{
			printf("玩家胜利！\n"); break;
		}
		else if (isWin(board, ROW, COL) == '#') {
			printf("电脑胜利！\n"); break;
		}
		else if (isWin(board, ROW, COL) == 'Q')
		{
			printf("平局！\n"); break;
		}

		
		//isWin(board, ROW, COL
		Computermove(board, ROW, COL);
		Displaybard(board, ROW, COL);
		if (isWin(board, ROW, COL) == '*')
		{
			printf("玩家胜利！\n"); break;
		}
		else if (isWin(board, ROW, COL) == '#') {
			printf("电脑胜利！\n"); break;
		}
		else if (isWin(board, ROW, COL) == 'Q')
		{
			printf("平局！\n"); break;
		}

		
	}
}
void test() {

	int input = 0;
	srand((unsigned int)time(NULL));
	do {

		menu();
		printf("请选择->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:game(); break;
		case 0:printf("退出游戏！\n"); break;
		default:printf("输入出错！\n"); break;
		}
	} while (input);
}
int main()
{

	test();
	return 0;
}


