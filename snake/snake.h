#include "../tui/tui.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>


namespace snake {
    struct position {
        bool lost;
        bool foodEx;
        play head;
        play tail;
        std::vector <play> snake;
        board Board;
    };
    position setup();
    position update(position snake, int dir);
    board food(board Board);
    int snake();
}

