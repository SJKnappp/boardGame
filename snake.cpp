#include "snake.h"
namespace snake{
    position setup(){
        position Snake;
        Snake.Board.border=false;
        Snake.Board.grid=false;
        Snake.Board.imidiate=true;
        Snake.Board.sizex=10;
        Snake.Board.sizey=10;
        

        for (int j=0;j<Snake.Board.sizey;j++){
            for(int i=0;i<Snake.Board.sizex;i++){
                Snake.Board.board[i][j].player=' ';
            }
        }

        Snake.Board.board[Snake.Board.sizex/2][Snake.Board.sizey/2].player='s';
        play head; head.x = Snake.Board.sizex/2; head.y = Snake.Board.sizey/2;
        Snake.snake.push_back(head);

        return Snake;
    }

    position update(position snake, int dir){
        
        play headold = snake.snake.at(0);
        play headnew;
        int x=0, y=0;
        
        
        if(dir==1){
            x=1;
        }else if(dir==2){
            x=-1;
        }else if(dir==3){
            y=+1;
        }else if(dir==4){
            y=-1;
        }
        headnew.x = x+headold.x; headnew.y=y+headold.y;
        snake.Board.board[headnew.x][headnew.y].player='s';
        snake.snake.insert(snake.snake.begin(), headnew);

        /*if(snake.snake.size()>2){}
        else{
            headold=snake.snake.back();
            snake.Board.board[headold.x][headold.y].player=' ';
        }*/

        return snake;
    }

    board food(board Board){
        int x;
        int y;
        bool put=false;

        while(put==false){
            x=rand() % Board.sizex;
            y=rand() % Board.sizey;

            //places food 
            if (Board.board[x][y].player==' '){
                Board.board[x][y].player='f';
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

        //reordes the position of the head and the tail
        position pos;
        

        //food intialise
        bool foodEx = false;

        bool running=true;
        while(running==true){
            usleep(100000);
            if(foodEx==false){
                snake.Board=food(snake.Board);
                foodEx=true;
            }
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