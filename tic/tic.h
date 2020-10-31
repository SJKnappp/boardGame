#ifndef TIC_H
#define  TIC_H

#include "../tui/type.h"
#include "../tui/tui.h"

namespace tic{
    board setup();
    int win(board Board);
    int tac();
}

#endif //TIC_H