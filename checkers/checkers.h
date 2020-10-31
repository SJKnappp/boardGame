#ifndef CHECKERS_H
#define CHECKERS_H

#include <iostream>
#include "curses.h"
#include "../tui/type.h"
#include "../tui/tui.h"

namespace checkers{
    board setup();
    bool allowed(board Board, bool isWhite, play start, play end);
    int checkwin(board Board);
    board move(board Board, play start, play end);
    int checkers();
}

#endif //CHECKERS_H