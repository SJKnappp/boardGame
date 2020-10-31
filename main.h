#include <iostream>
#include <string>
#include <cmath>
#include <ncurses.h>
#include <stdlib.h>
#include <vector>
#include <unistd.h>

#include "checkers/checkers.h"
#include "snake/snake.h"
#include "tic/tic.h"
#include "tui/type.h"
#include "tui/tui.h"

inline bool operator==(const play& lhs, const int& rhs){
    return lhs.x ==rhs && lhs.y==rhs;
}



void print(char player, board Board);
play input(int xmax, int ymax);
play tui(char player, board Board);
char menu();
