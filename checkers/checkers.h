#include "../type.h"

namespace checkers{
    board setup();
    bool allowed(board Board, bool isWhite, play start, play end);
    int checkwin(board Board);
    board move(board Board, play start, play end);
    int checkers();
}