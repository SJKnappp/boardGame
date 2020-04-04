#include "main.h"
#include "checkers.cpp"
#include "tic.cpp"
#include "snake.cpp"

play tui(char player, board Board){
	//colours defined here
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_BLACK, COLOR_WHITE);
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

	WINDOW *win =newwin(30, 30, 20, 20);

	while(accept==false){
		if(player==' '){accept=true; moved=true;}
		mvprintw(1, 0, "%d %d", grid[0], grid[1]);
		//refresh();
		if(first==true){first=false;}
		else{move = getch();}
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

		if(true){
			//refresh();
			moved=false;
			mvprintw(0, 0, "player test%c", player);
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
						mvprintw(startgrid[1]+2*j, startgrid[0]+4*i+1, "H");}
					else{
						if(Board.board[i][j].player==' ' || Board.board[i][j].player=='w'){attron(COLOR_PAIR(1));}
						else{attron(COLOR_PAIR(2));}
						mvprintw(startgrid[1]+2*j, startgrid[0]+4*i+1, "%c", Board.board[i][j].player);
					}
					attron(COLOR_PAIR(1));
					//draws seperating lines if grid is turned on
					if(Board.grid==true){mvprintw(startgrid[1]+2*j, startgrid[0]+4*i+3,"|");}

				}
				if(Board.border==true){mvprintw(startgrid[1]+2*j+1, startgrid[0]-1, "%s", line.c_str());}
			}
			
		}
	}
	return Move;
}

char menu(){

	char val;
	printw("choses your game\n");
	printw("1-checkers 2-tic-tac-toe 3-snake\n");
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
	switch(choce){
	case '1':
		checkers();
		break;
	case '2':
		tic::tac();
		break;
	case '3':
		snake::snake();
		break;
	}
	endwin();
	return 0;
}
