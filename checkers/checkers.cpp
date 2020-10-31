#include "checkers.h"

namespace checkers {
    board setup() {
        board Board;

        Board.sizex = 8;
        Board.sizey = 8;

        for (int j = 0; j < Board.sizey; j++) {
            for (int i = 0; i < Board.sizex; i++) {
                Board.board[i][j].player = ' ';
                Board.board[i][j].peice = ' ';
            }
        }

        Board.board[0][0].player = 'w';
        Board.board[2][0].player = 'w';
        Board.board[4][0].player = 'w';
        Board.board[6][0].player = 'w';
        Board.board[1][1].player = 'w';
        Board.board[3][1].player = 'w';
        Board.board[5][1].player = 'w';
        Board.board[7][1].player = 'w';
        Board.board[0][2].player = 'w';
        Board.board[2][2].player = 'w';
        Board.board[4][2].player = 'w';
        Board.board[6][2].player = 'w';

        Board.board[1][5].player = 'b';
        Board.board[3][5].player = 'b';
        Board.board[5][5].player = 'b';
        Board.board[7][5].player = 'b';
        Board.board[0][6].player = 'b';
        Board.board[2][6].player = 'b';
        Board.board[4][6].player = 'b';
        Board.board[6][6].player = 'b';
        Board.board[1][7].player = 'b';
        Board.board[3][7].player = 'b';
        Board.board[5][7].player = 'b';
        Board.board[7][7].player = 'b';
        return Board;
    }

    bool allowed(board Board, bool isWhite, play start, play end) {
        int dir = 1;
        char player;
        char oppo;
        if (isWhite == false) {
            dir = -1;
            player = 'b';
            oppo = 'w';
        } else {
            player = 'w';
            oppo = 'b';
        }

        //checks starts at player location
        if (Board.board[start.x][start.y].player != player) {
            printw("1");
            return false;
        }
        //checks end move is free
        if (Board.board[end.x][end.y].player != ' ') {
            printw("2");
            return false;
        }
        //moves in diagonals
        if (abs(start.x - end.x) != abs(start.y - end.y)) {
            printw("3");
            return false;
        }
        //checks moving no more than 2
        if (abs(start.x - end.x) > 2) {
            printw("4");
            return false;
        }
        //checks middle if moving 2
        if (abs(start.x - end.x) == 2) {
            if (Board.board[start.x + 1][start.y + dir].player == oppo) {}
            else if (Board.board[start.x - 1][start.y + dir].player != oppo) {}
            else {
                printw("5");
                return false;
            }
        }

        return true;
    }

//checks victory condition
    int checkwin(board Board) {

        //A
        //counters for how many pices
        int white = 0;
        int black = 0;

        for (int j = 0; j < Board.sizey; j++) {
            for (int i = 0; i < Board.sizey; i++) {
                if (white > 0 && black > 0) {
                    return 0;
                }
                if (Board.board[i][j].player == 'w') {
                    white += 1;
                } else if (Board.board[i][j].player == 'b') {
                    black += 1;
                }
            }
        }
        if (white == 0) {
            return 1;
        } else if (black == 0) {
            return 2;
        }
        return 0;
    }

    board move(board Board, play start, play end) {
        if (abs(start.x - end.x) == 2) {
            Board.board[start.x + (end.x - start.x) / 2][start.y + (end.y - start.y) / 2].player = ' ';
        }
        Board.board[end.x][end.y] = Board.board[start.x][start.y];
        Board.board[start.x][start.y].player = ' ';
        return Board;
    }

    int checkers() {
        board Board;
        Board = setup();


        bool running = true;
        bool isWhite = true;
        bool finished = false;
        bool allow = false;
        int check;
        char currentPlayer = 'w';
        play start;
        play end;

        //prints intial state
        //print(currentPlayer, Board);

        while (running == true) {

            printw("please input start peace: ");
            //start=input(Board.sizex, Board.sizey);
            start = tui(currentPlayer, Board);
            clear();
            printw("please enter move: ");
            //end=input(Board.sizex, Board.sizey);
            end = tui(currentPlayer, Board);

            //checks allowed
            clear();
            allow = allowed(Board, isWhite, start, end);
            getch();
            if (allow == true) {
                if (abs(start.x - end.x) == 1) { finished = true; }
                //moves the peice
                Board = move(Board, start, end);

                //checks win
                check = checkwin(Board);
                if (check == 1) {
                    std::cout << "black win" << std::endl;
                    return 0;
                }
                if (check == 2) {
                    std::cout << "white win" << std::endl;
                    return 0;
                }

                //last check if finished == true change player
                if (finished == true) {
                    finished = false;
                    if (isWhite == true) { isWhite = false; }
                    else { isWhite = true; }
                    if (currentPlayer == 'w') { currentPlayer = 'b'; } else { currentPlayer = 'w'; }
                    //print(currentPlayer, Board);
                }
            }
        }

        return 0;
    }
}
