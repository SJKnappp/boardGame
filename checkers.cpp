
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

int checkers(){
	board Board;
	Board = setup();
	print('w', Board);
	return 0;
}
