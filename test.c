#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

int main()
{
	char arr[ROW][COL] = { 0 };
	int input = 0;
	do
	{
		menu();
		printf("请选择>>>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			initarr(arr, ROW, COL);
			display(arr,ROW,COL);
			playgame(arr, ROW, COL);
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入无效，重新输入\n");
			break;
		}
	} while (input);


	return 0;
}