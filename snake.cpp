#include "snake.h"
namespace snake{
    position setup(){
        position snake;
        board Board;
        Board.border=true;
        Board.grid=false;
        Board.imidiate=true;
        Board.sizex=10;
        Board.sizey=10;
        

        for (int j=0;j<Board.sizey;j++){
            for(int i=0;i<Board.sizex;i++){
                Board.board[i][j].player=' ';
            }
        }

        Board.board[Board.sizex/2][Board.sizey/2].peice='s';
        snake.Board=Board;

        snake.head.x=Board.sizex/2; snake.tail.y=Board.sizey/2;
        snake.tail.x=-1; snake.tail.y=-1;

        return snake;
    }

    position update(position snake, int dir){
        
        play headold = snake.snake.at(0);
        
        if(dir==1){
            snake.Board.board[snake.head.x+1][snake.head.y].player='s';
        }else if(dir==2){
            snake.Board.board[snake.head.x-1][snake.head.y].player='s';
        }else if(dir==3){
            snake.Board.board[snake.head.x][snake.head.y+1].player='s';
        }else if(dir==4){
            snake.Board.board[snake.head.x][snake.head.y-1].player='s';
        }

        return snake;
    }

    board food(board Board){
        int x;
        int y;
        bool put=true;

        while(put==false){
            x=rand() % Board.sizex;
            y=rand() % Board.sizey;

            //places food 
            if (Board.board[x][y].player==' '){
                Board.board[x][y].player=='f';
                put = true;
            }
        }
        return Board;
    }

    int snake(){
        clear();
        position snake = setup();
        play Move;
        play temp;
        getch();

        //reordes the position of the head and the tail
        position pos;
        

        //food intialise
        bool foodEx =false;

        bool running=true;
        while(running==true){
            if(foodEx==false){snake.Board=food(snake.Board);}
            temp=tui(' ', snake.Board);
            if(temp==0){}
            else{Move=temp;}
            if(Move.x == 1 && Move.y == 0){snake=update(snake, 1);}
            else if(Move.x == -1 && Move.y == 0){snake=update(snake, 2);}
            else if(Move.x == 0 && Move.y == 1){snake=update(snake, 3);}
            else if(Move.x == 0 && Move.y == -1){snake=update(snake, 4);}
        }

        return 0;
    }
}