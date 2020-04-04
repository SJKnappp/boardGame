#include <iostream>
#include <string>
#include <cmath>
#include <ncurses.h>
#include <stdlib.h>
#include <vector>

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
	bool grid=true;
	bool border=true;
	bool imidiate=false;
};

struct play{
	int x;
	int y;
};
inline bool operator==(const play& lhs, const int& rhs){
    return lhs.x ==rhs && lhs.y==rhs;
}



void print(char player, board Board);
play input(int xmax, int ymax);
play tui(char player, board Board);
char menu();
