#include <iostream>
#include <string>

struct board{
	char board[19][19];
	char p1;
	char p2;
	int sizex;
	int sizey;
};

void print(char player, board Board);
