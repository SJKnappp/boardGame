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
	play Move;
	int grid[2]={0, 0};
	int current[2]={0, 0};
	bool accept=false;
	bool moved=false;
	char move;

	while(accept==false){
		accept=false;
		move =getch();
		switch (move)
		{
		case 'h': //left
			if (grid[0]>0){grid[0]-1;}
			break;
		case 'j': //down
			if (grid[0]>0){grid[1]+1;}
			break;
		case 'k': //up
			if (grid[0]>0){grid[1]-1;}
			break;
		case 'l': //right
			if (grid[0]>0){grid[0]+1;}
			break;
		default:
			break;
		}

		if(accept==true){
		refresh();

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
			move(0, 0);
			refresh();
			std::cout << j+1 <<  "  | ";
			for(int i=0;i<Board.sizex;i++){
				
				if(i==grid[0]&&j==grid[1]){std::cout << "H  | ";}
				else{std::cout << Board.board[i][j].player << " | ";}
			}
			std::cout << std::endl << "    " << line << std::endl;
		}
		std::cout << std::endl;
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
