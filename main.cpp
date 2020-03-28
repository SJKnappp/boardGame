#include "main.h"
#include "checkers.cpp"

void print(char player, board Board){
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
		std::cout << "input failed please retry";
		std::cin >> move;
	}
	return Play;
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
