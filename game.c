#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu(void)
{
	printf("**********  三子棋  **********\n");
	printf("***[1]开始游戏   [0]退出游戏***\n");
	printf("******************************\n");
}

void initarr(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row ; i++)
	{
		int j = 0;
		for (j = 0; j < col ; j++)
		{
			arr[i][j] = ' ';
		}
	}
}

//   |   |   
//---|---|---
//   |   |   
//---|---|---
//   |   |   

void display(char arr[ROW][COL], int row, int col)
{
	printf("\n");
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j < col - 1)
				printf("|");
			else
				printf("\n");
		}
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
				else
					printf("\n");
			}
		}
	}
}

void playgame(char arr[ROW][COL], int row, int col)
{
	srand((unsigned int)time(NULL));
	while (1)
	{
		//玩家下
		playermove(arr, ROW, COL);
		display(arr, ROW, COL);
		if (iswin(arr, ROW, COL) == '*')
		{
			printf("玩家赢\n");
			break;
		}
		else if (iswin(arr, ROW, COL) == '#')
		{
			printf("电脑赢\n");
			break;
		}
		else if (iswin(arr, ROW, COL) == 'Q')
		{
			printf("平局\n");
			break;
		}
		else
		{

		}
		//电脑下
		computermove(arr, ROW, COL);
		display(arr, ROW, COL);
		//判断玩家赢
		if (iswin(arr, ROW, COL) == '*')
		{
			printf("玩家赢\n");
			break;
		}
		else if (iswin(arr, ROW, COL) == '#')
		{
			printf("电脑赢\n");
			break;
		}
		else if (iswin(arr, ROW, COL) == 'Q')
		{
			printf("平局\n");
			break;
		}
		else
		{

		}
	}
}


void playermove(char arr[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请输入要下的坐标>>>:");
		scanf("%d%d", &x, &y);
		if (x <= ROW && y <= COL)
		{
			if (arr[x - 1][y - 1] == ' ')
			{
				arr[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标被占用\n");
			}
		}
		else
		{
			printf("该坐标非法\n");
		}
	}
}

void computermove(char arr[ROW][COL],int row,int col)
{
	printf("电脑:");
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % ROW;
		y = rand() % COL;
		if (x < ROW && y < COL&& arr[x][y] == ' ')
		{
				arr[x][y] = '#';
				break;
		}
	}
}

//return * 玩家赢
//return # 电脑赢
//return C 继续
//return Q 平局
char iswin(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int pcount = 0;
	int ccount = 0;

	//判断行
	for (i = 0; i < ROW; i++)
	{
		pcount = 0;
		ccount = 0;
		for (j = 0; j < COL; j++)
		{
			if (arr[i][j] == '*')
			{
				pcount++;
			}
			else if (arr[i][j] == '#')
			{
				ccount++;
			}
		}
		if (pcount == COL || ccount == COL)
		{
			return arr[i][0];
		}
	}
	//判断列
	for (j = 0; j < COL; j++)
	{
		pcount = 0;
		ccount = 0;
		for (i = 0; i < ROW; i++)
		{
			if (arr[i][j] == '*')
			{
				pcount++;
			}
			else if (arr[i][j] == '#')
			{
				ccount++;
			}
		}
		if (pcount == ROW || ccount == ROW)
		{
			return arr[0][j];
		}
	}
	//判断右斜线
	pcount = 0;
	ccount = 0;
	for (i = 0; i < ROW; i++)
	{
		if (arr[i][i] == '*')
		{
			pcount++;
		}
		else if (arr[i][i] == '#')
		{
			ccount++;
		}
		if (pcount == ROW || ccount == ROW)
		{
			return arr[0][0];
		}
	}
	//判断左斜线
	pcount = 0;
	ccount = 0;
	for (i=0;i<ROW;i++)
	{
		if (arr[i][ROW-i-1] == '*')
		{
			pcount++;
		}
		else if (arr[i][ROW - i-1] == '#')
		{
			ccount++;
		}
		if (pcount == ROW || ccount == ROW)
		{
			return arr[0][ROW-1];
		}
	}
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (arr[i][j] == ' ')
			{
				return 'C';
			}
		}
	}
	if (i == ROW && j == COL)
	{
		return 'Q';
	}
}