//
// Created by knapp on 05/10/2020.
//

#include "tui.h"

play tui(char player, board Board){
    //colours defined here
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_YELLOW);
    init_pair(3, COLOR_BLUE, COLOR_BLUE);
    init_pair(4, COLOR_RED, COLOR_RED);
    init_pair(5, COLOR_BLACK, COLOR_RED);

    attron(COLOR_PAIR(1));
    refresh();
    play Move;
    int grid[2]={0, 0};
    int startgrid[2]={4, 4};
    int current[2]={0, 0};
    bool accept=false;
    bool moved=true;
    bool first = true;
    char move=' ';
    int row=0;
    int col=4;

    if(Board.grid==false){
        col=1;
    }

    WINDOW *win =newwin(30, 30, 20, 20);

    while(accept==false){
        if(Board.imidiate==true){nodelay(stdscr, true);}
        if(player==' '){accept=true; moved=true;}
        mvprintw(1, 0, "%d %d", grid[0], grid[1]);
        //refresh();
        move = getch();
        //else{printw("jsjsjs");}

        switch (move)
        {
            case 'h': //left
                if (grid[0]>0){grid[0]-=1;}
                if(Board.imidiate==true){Move.x=-1; Move.y=0;}
                moved=true;
                break;
            case 'j': //down
                if (grid[1]<Board.sizey-1){grid[1]+=1;}
                if(Board.imidiate==true){Move.x=0; Move.y=1;}
                moved=true;
                break;
            case 'k': //up
                if (grid[1]>0){grid[1]-=1;}
                if(Board.imidiate==true){Move.x=0; Move.y=-1;}
                moved=true;
                break;
            case 'l': //right
                if (grid[0]<Board.sizex-1){grid[0]+=1;}
                if(Board.imidiate==true){Move.x=1; Move.y=0;}
                moved=true;
                break;
            case '\n': //return pressed
                if(Board.imidiate==false){
                    accept=true;
                    Move.x=grid[0];
                    Move.y=grid[1];
                }
                break;
            default:
                break;
        }

        if(moved==true){
            row=0;
            refresh();
            moved=false;
            if(player!=' '){mvprintw(0, 0, "player %c", player);}
            std::string line;
            for (int i=0;i<Board.sizex*3+Board.sizex+1;i++){
                if(i%4==0){line.append("+");}
                else{line.append("-");}
            }
            line.append("\0");

            //draws top line if grid is turned on
            if(Board.grid==true){mvprintw(startgrid[1]-1, startgrid[0]-1, "%s", line.c_str());}

            char temp='a';
            char val ='1';
            for (int j = 0;j<Board.sizey;j++){
                //draws cords and left hand line if grid is turned on
                if(Board.grid==true){
                    mvprintw(startgrid[1]+2*j, startgrid[0]-3, "%c%s", val, " |");
                    mvprintw(startgrid[1]-2, startgrid[0]+4*j+1, "%c", temp);
                    val+=1;
                    temp+=1;
                }
                for(int i=0;i<Board.sizex;i++){

                    if(i==grid[0]&&j==grid[1]&&Board.imidiate==false){attron(COLOR_PAIR(3));
                        mvprintw(startgrid[1]+2*j, startgrid[0]+col*i+1, "H");}
                    else{
                        if(Board.board[i][j].player==' ' || Board.board[i][j].player=='w'){attron(COLOR_PAIR(1));}
                        else if(Board.board[i][j].player=='s'){attron(COLOR_PAIR(3));}
                        else if(Board.board[i][j].player=='f'){attron(COLOR_PAIR(4));}
                        else{attron(COLOR_PAIR(2));}
                        mvprintw(startgrid[1]+j+row, startgrid[0]+col*i+1, "%c", Board.board[i][j].player);
                    }
                    attron(COLOR_PAIR(1));
                    //draws seperating lines if grid is turned on
                    if(Board.grid==true){mvprintw(startgrid[1]+j+row, startgrid[0]+col*i+3,"|");}

                }
                if(Board.border==true){row+=1; mvprintw(startgrid[1]+j+row, startgrid[0]-1, "%s", line.c_str());}
            }
            refresh();
            getch();
        }
    }
    return Move;
}