#include <iostream>
#include <string>
#include <cmath>

struct piece{
	char player;
	char peice;
};

struct board{
	piece board[19][19];
	char p1;
	char p2;
	int sizex;
	int sizey;
};

struct play{
	int x;
	int y;
};



void print(char player, board Board);
play input(int xmax, int ymax);
int menu();
