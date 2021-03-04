#pragma once

#ifndef  __GAME_H__
#define  __GAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3

void menu(void);
void initarr(char arr[ROW][COL], int row, int col);
void display(char arr[ROW][COL],int row, int col);
void playgame(char arr[ROW][COL], int row, int col);
void playermove(char arr[ROW][COL], int row, int col);
void computermove(char arr[ROW][COL], int row, int col);
char iswin(char arr[ROW][COL], int row, int col);
int fullover(char arr[ROW][COL], int row, int col);
#endif // !__GAME_H__

