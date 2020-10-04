namespace tic{

    board setup(){
        board Board;

        Board.sizex=3;
        Board.sizey=3;

        for(int j=0;j<Board.sizey;j++){
            for(int i=0;i<Board.sizex;i++){
                Board.board[i][j].player=' ';
            }
        }
        return Board;
    }

    int win(board Board){
        
        char winner[8];
        if(Board.board[0][0].player==Board.board[1][0].player&&Board.board[0][0].player==Board.board[2][0].player){winner[0]=Board.board[0][0].player;}
        if(Board.board[0][1].player==Board.board[1][1].player&&Board.board[0][1].player==Board.board[2][1].player){winner[1]=Board.board[0][1].player;}
        if(Board.board[0][2].player==Board.board[1][2].player&&Board.board[0][2].player==Board.board[2][2].player){winner[2]=Board.board[0][2].player;}
        if(Board.board[0][0].player==Board.board[0][1].player&&Board.board[0][0].player==Board.board[0][2].player){winner[3]=Board.board[0][0].player;}
        if(Board.board[1][0].player==Board.board[1][1].player&&Board.board[1][0].player==Board.board[1][2].player){winner[4]=Board.board[1][0].player;}
        if(Board.board[2][0].player==Board.board[2][1].player&&Board.board[2][0].player==Board.board[2][2].player){winner[5]=Board.board[2][0].player;}
        if(Board.board[0][0].player==Board.board[1][1].player&&Board.board[0][0].player==Board.board[2][2].player){winner[6]=Board.board[0][0].player;}
        if(Board.board[2][0].player==Board.board[1][1].player&&Board.board[2][0].player==Board.board[0][2].player){winner[7]=Board.board[2][0].player;}

        for(int i=0;i<8;i++){
              if(winner[i]=='x'){return 1;}
              else if(winner[i]=='o'){return 2;}
        }
      
        return 0;
    }

    int tac(){
        board Board = setup();
        //initalise
        int winval;
        bool running = true;
        bool accepted =false;
        char player='x';

        while(running==true){
            //takes input
            play move = tui(player, Board);

            if(Board.board[move.x][move.y].player==' '){
                Board.board[move.x][move.y].player=player;
                accepted=true;
            }

            //check win
            winval=win(Board);
            if(winval==1){
                return 0;
            }else if(winval==2){
                return 0;
            }

            if(accepted==true){
            //swaps player
            if(player=='x'){player='o';}
            else{player='x';}
            accepted=false;
            }
        }
        return 0;
    }
}