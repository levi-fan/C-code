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
			printf("���ʤ����\n"); break;
		}
		else if (isWin(board, ROW, COL) == '#') {
			printf("����ʤ����\n"); break;
		}
		else if (isWin(board, ROW, COL) == 'Q')
		{
			printf("ƽ�֣�\n"); break;
		}

		
		//isWin(board, ROW, COL
		Computermove(board, ROW, COL);
		Displaybard(board, ROW, COL);
		if (isWin(board, ROW, COL) == '*')
		{
			printf("���ʤ����\n"); break;
		}
		else if (isWin(board, ROW, COL) == '#') {
			printf("����ʤ����\n"); break;
		}
		else if (isWin(board, ROW, COL) == 'Q')
		{
			printf("ƽ�֣�\n"); break;
		}

		
	}
}
void test() {

	int input = 0;
	srand((unsigned int)time(NULL));
	do {

		menu();
		printf("��ѡ��->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:game(); break;
		case 0:printf("�˳���Ϸ��\n"); break;
		default:printf("�������\n"); break;
		}
	} while (input);
}
int main()
{

	test();
	return 0;
}


