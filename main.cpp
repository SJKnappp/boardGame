#include "main.h"
#include "checkers.cpp"

void print(char player, board Board){
	
	std::cout << std::string(100, '\n');

	std::cout << "player " << player << std::endl << std::endl;
	std::string line;
	for (int i=0;i<Board.sizex*3+Board.sizex;i++){
		line.append("-");
	}

	char temp='a';
	std::cout<<"  ";
	for (int i=0;i<Board.sizex;i++){
		std::cout << "   " << temp;
		temp+=1;
	}
	std::cout <<std::endl<<std::endl;

	for (int j = 0;j<Board.sizey;j++){
	std::cout << j+1 <<  "  | ";
		for(int i=0;i<Board.sizex;i++){
			std::cout << Board.board[i][j].player << " | ";
		}
		std::cout << std::endl << "    " << line << std::endl;
	}
	std::cout << std::endl;

}

play tui(char player, board Board){
	clear();
	play Move;
	int grid[2]={0, 0};
	int current[2]={0, 0};
	bool accept=false;
	bool moved=true;
	bool first = true;
	char move;

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

			char temp='a';
			printw("  ");
			for (int i=0;i<Board.sizex;i++){
				mvprintw(2, i, "   %c", temp);
				temp+=1;
			}
			printw("\n\n");

			for (int j = 0;j<Board.sizey;j++){
				char val ='1';
				mvprintw(0, 0, &val, "  | ");
				val+=1;
				for(int i=0;i<Board.sizex;i++){
				
					if(i==grid[0]&&j==grid[1]){mvprintw(2*j+3, 5*i+3, "H |");}
					else{mvprintw(2*j+3, 5*i+3, "%c%s", Board.board[i][j].player, " |");}
				}
				mvprintw(2*j+4, 0, "    %s", line);
			}
			refresh();
		}
	}
	return Move;
}

play input(int xmax, int ymax){
	play Play;
	std::string move;
	std::cin >> move;
	bool check = true;
	while(check ==true){
		if(move.length() == 2){
			Play.x = move.at(0)-97;
			Play.y = move.at(1)-49;
			if (Play.x >= 0 && Play.x < xmax && Play.y >=0 && Play.y < ymax){
				break;
			}
		}else if(move.length() == 3){
			Play.x = move.at(0)-97;
			Play.y = 10*(move.at(1)-49) + move.at(2)-49;
			if (Play.x >= 0 && Play.x < xmax && Play.y >=0 && Play.y < ymax){
				break;
			}
		}
		std::cout << "input failed please retry: ";
		std::cin >> move;
	}
	return Play;
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
