#include "main.h"
#include "checkers.cpp"

void print(char player, board Board){
	std::cout << "player " << player << std::endl << std::endl;
	std::string line;
	for (int i=0;i<Board.sizex*3+Board.sizex;i++){
		line.append("-");
	}

	for (int i=0;i<Board.sizex;i++){
		std::cout << "   " << i+1;
	}
	std::cout << std::endl;

	for (int j = 0;j<Board.sizey;j++){
	std::cout << j+1 <<  "  | ";
		for(int i=0;i<Board.sizex;i++){
			if (Board.board[i][j] == ' '){
				std::cout << "t   | "; 
			}else{
				std::cout << Board.board[i][j] << " | ";
			}
		}
		std::cout << std::endl << "  " << line << std::endl;
	}

}

int menu(){

	int val;
	std::cout << "choses your game" << std::endl;
	std::cin >> val;
	return val;

}

int main(){

	board Board;
	Board = setup();
	int choce;
	choce = menu();
	switch(choce)
		case 1:
			checkers();
	return 0;
}
