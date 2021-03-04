#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu(void)
{
	printf("**********  ������  **********\n");
	printf("***[1]��ʼ��Ϸ   [0]�˳���Ϸ***\n");
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
		//�����
		playermove(arr, ROW, COL);
		display(arr, ROW, COL);
		if (iswin(arr, ROW, COL) == '*')
		{
			printf("���Ӯ\n");
			break;
		}
		else if (iswin(arr, ROW, COL) == '#')
		{
			printf("����Ӯ\n");
			break;
		}
		else if (iswin(arr, ROW, COL) == 'Q')
		{
			printf("ƽ��\n");
			break;
		}
		else
		{

		}
		//������
		computermove(arr, ROW, COL);
		display(arr, ROW, COL);
		//�ж����Ӯ
		if (iswin(arr, ROW, COL) == '*')
		{
			printf("���Ӯ\n");
			break;
		}
		else if (iswin(arr, ROW, COL) == '#')
		{
			printf("����Ӯ\n");
			break;
		}
		else if (iswin(arr, ROW, COL) == 'Q')
		{
			printf("ƽ��\n");
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
		printf("������Ҫ�µ�����>>>:");
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
				printf("�����걻ռ��\n");
			}
		}
		else
		{
			printf("������Ƿ�\n");
		}
	}
}

void computermove(char arr[ROW][COL],int row,int col)
{
	printf("����:");
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

//return * ���Ӯ
//return # ����Ӯ
//return C ����
//return Q ƽ��
char iswin(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int pcount = 0;
	int ccount = 0;

	//�ж���
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
	//�ж���
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
	//�ж���б��
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
	//�ж���б��
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