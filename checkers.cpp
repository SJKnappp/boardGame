
board setup(){
	board Board;

	Board.sizex = 8;
	Board.sizey = 8;

	for(int j=0;j++;j<Board.sizey){
		for(int i=0;i++;i<Board.sizex){
			Board.board[i][j].player=' ';
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

bool allowed(board Board, bool isWhite, play start, play end){
	int dir = 1;
	char player;
	if(isWhite==false){
		dir=-1;
		player='b';
	}else{player='w';}

	
	if(Board.board[start.x][start.y].player!=player){
		return false;	
	}
	
	return true;
}

//checks victory condition
int checkwin(board Board){

	//counters for how many pices
	int white=0;
	int black=0;

	for(int j=0;j<Board.sizey;j++){
		for(int i=0;i<Board.sizey;i++){
			if(white>0 && black>0){
				return 0;
			}
			if(Board.board[i][j].player == 'w'){
				white+=1;	
			}
			else if(Board.board[i][j].player == 'w'){ 
				black+=1;
			}
		}
	}
	if(white==0){
		return 1;
	}else if(black==0){
		return 2;
	}return 0;
}

board move(board Board, play start, play end){

	Board.board[end.x][end.y]=Board.board[start.x][start.y];
	Board.board[start.x][start.y].player==' ';

	return Board;
}

int checkers(){
	board Board;
	Board = setup();
	print('w', Board);

	bool running;
	bool isWhite = true;
	bool finished = false;
	bool allow= false;
	int check;
	play start;
	play end;
	while(running == true){

		std::cout << "please input start peace";
		start=input(Board.sizex, Board.sizey);				
				
		std::cout << "please enter move";
		end=input(Board.sizex, Board.sizey);
		
		//checks allowed
		allow = allowed(Board, isWhite, start, end);
		if(allow==true){
		
		//moves the peice
		Board=move(Board, start, end);

		//checks win
		check = checkwin(Board);
		if(check==1){
			std::cout<<"black win"<<std::endl;
		}
		if(check==2){
			std::cout<<"white win"<<std::endl;
		}

		//last check if finished == true change player
		if (finished == true){
			if(isWhite == true){isWhite = false;} 
			else {isWhite = false;}
		}
		}
	}
	
	return 0;
}
