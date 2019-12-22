#include<iostream>
#include<Windows.h>
#include"GUI.h"
using namespace std;

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
	return 0;
}

void GUI(int a, int b, int c, int d, int col)//a,b '-';c,d'|';
{
	int i, j = 1;
	color(col);
	for (i = a; i <= b; i++)
	{
		for (j = c; j <= d; j++)
		{
			gotoxy(j, i);
			if (i == a || i == b)cout << "-";
			else if (j == c || j == d)cout << "|";
		}
	}
}