
board setup(){
	board Board;

	Board.sizex = 8;
	Board.sizey = 8;

	for(int j=0;j++;j<Board.sizey){
		for(int i=0;i++;i<Board.sizex){
			Board.board[i][j]=' ';
		}
	}
	
	Board.board[0][0] = 'w';
	Board.board[2][0] = 'w';
	Board.board[4][0] = 'w';
	Board.board[6][0] = 'w';
	Board.board[1][1] = 'w';
	Board.board[3][1] = 'w';
	Board.board[5][1] = 'w';
	Board.board[7][1] = 'w';
	Board.board[0][2] = 'w';
	Board.board[2][2] = 'w';
	Board.board[4][2] = 'w';
	Board.board[6][2] = 'w';

	Board.board[1][5] = 'b';
	Board.board[3][5] = 'b';
	Board.board[5][5] = 'b';
	Board.board[7][5] = 'b';
	Board.board[0][6] = 'b';
	Board.board[2][6] = 'b';
	Board.board[4][6] = 'b';
	Board.board[6][6] = 'b';
	Board.board[1][7] = 'b';
	Board.board[3][7] = 'b';
	Board.board[5][7] = 'b';
	Board.board[7][7] = 'b';
	return Board;
}

bool allowed(board Board){
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
			if(Board.board[i][j] == 'w'){
				white+=1;	
			}
			else if(Board.board[i][j] == 'w'){ 
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

int checkers(){
	board Board;
	Board = setup();
	print('w', Board);

	bool running;
	bool isWhite = true;
	bool finished = false;
	int check;
	while(running == true){

		std::cout << "please input start peace";
		input(Board.sizex, Board.sizey);				
				
		std::cout << "please enter move";
		input(Board.sizex, Board.sizey);
		


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
	

	return 0;
}
