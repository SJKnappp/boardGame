#include "main.h"
//#include "checkers.cpp"
//#include "tic.cpp"
//#include "snake.cpp"


char menu(){

	char val;
	printw("choses your game\n");
	printw("1-checkers 2-tic-tac-toe 3-snake\nq to quit");
	val=getch();
	return val;
}

int main(){
	initscr();
	clear();
	cbreak();
	noecho();
	board Board;
	//Board = setup();
	char choce;
	bool gameing =true;
	while(gameing==true){
		clear();
		nodelay(stdscr, false);
		choce = menu();
		switch(choce){
		case '1':
			checkers::checkers();
			break;
		case '2':
			tic::tac();
			break;
		case '3':
			snake::snake();
			break;
		case 'q':
			gameing=false;
			break;
		}
	}
	endwin();
	return 0;
}
