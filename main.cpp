#include "main.h"
#include "checkers.cpp"

play tui(char player, board Board){
	clear();
	play Move;
	int grid[2]={0, 0};
	int startgrid[2]={4, 4};
	int current[2]={0, 0};
	bool accept=false;
	bool moved=true;
	bool first = true;
	char move=' ';

	WINDOW *win =newwin(30, 30, 20, 20);

	while(accept==false){
		mvprintw(1, 0, "%d %d", grid[0], grid[1]);
		if(first==true){first=false;}
		else{move =getch();}
		switch (move)
		{
		case 'h': //left
			if (grid[0]>0){grid[0]-=1;}
			moved=true;
			break;
		case 'j': //down
			if (grid[1]<7){grid[1]+=1;}
			moved=true;
			break;
		case 'k': //up
			if (grid[1]>0){grid[1]-=1;}
			moved=true;
			break;
		case 'l': //right
			if (grid[0]<7){grid[0]+=1;}
			moved=true;
			break;
		case '\n': //return pressed
			accept=true;
			Move.x=grid[0];
			Move.y=grid[1];
			break;
		default:
			break;
		}

		if(moved==true){
			moved=false;
			mvprintw(0, 0, "player %c", player);
			std::string line;
			for (int i=0;i<Board.sizex*3+Board.sizex;i++){
				line.append("-");
			}
			line.append("\0");

			mvprintw(startgrid[1]-1, startgrid[0], "%s", line.c_str());

			char temp='a';
			char val ='1';
			for (int j = 0;j<Board.sizey;j++){
				
				mvprintw(startgrid[1]+2*j, startgrid[0]-3, "%c%s", val, " |");
				mvprintw(startgrid[1]-2, startgrid[0]+4*j+1, "%c", temp);
				val+=1;
				temp+=1;
				for(int i=0;i<Board.sizex;i++){
				
					if(i==grid[0]&&j==grid[1]){mvprintw(startgrid[1]+2*j, startgrid[0]+4*i+1, "H |");}
					else{mvprintw(startgrid[1]+2*j, startgrid[0]+4*i+1, "%c%s", Board.board[i][j].player, " |");}
				}
				mvprintw(startgrid[1]+2*j+1, startgrid[0], "%s", line.c_str());
			}
			refresh();
		}
	}
	return Move;
}

char menu(){

	char val;
	printw("choses your game\n");
	printw("1-checkers\n");
	val=getch();
	return val;
}

int main(){
	initscr();
	clear();
	cbreak();
	noecho();
	board Board;
	Board = setup();
	char choce;
	choce = menu();
	switch(choce)
		case '1':
			checkers();

	endwin();
	return 0;
}
