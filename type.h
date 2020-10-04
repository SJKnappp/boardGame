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