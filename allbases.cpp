//all your base are blong to us!!!
//console ncurses screen saver
//compile using g++ allbases.cpp -o bases -lncurses
#include <cstdlib>
#include <ncurses.h>
#include <time.h>
int main(){
	int cp;
	initscr();
   	noecho();
   	cbreak();
   	timeout(0);
	curs_set(0);
	srand (time(NULL));
        start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(8, COLOR_BLACK, COLOR_GREEN);
	init_pair(9, COLOR_BLACK, COLOR_WHITE);
	init_pair(10, COLOR_BLACK, COLOR_BLUE);
	init_pair(11, COLOR_BLACK, COLOR_RED);
	init_pair(12, COLOR_BLACK, COLOR_YELLOW);
	init_pair(13, COLOR_BLACK, COLOR_CYAN);
	init_pair(14, COLOR_BLACK, COLOR_MAGENTA);
	do{
		cp = rand() % 14 + 1;
		attron(COLOR_PAIR(cp));
		int vx, vy;
		vx = rand() % COLS;
		vy = rand() % LINES;
		keypad(stdscr, TRUE);
		mvprintw(vy, vx, "all your base are belong to us!!!");
		attroff(COLOR_PAIR(cp));
	        refresh();
		int c;
		c = getch();
		if (c==113 || c==27 || c==32 | c==13 || c==10){break;}
	}while(1==1);
        endwin();
	return 0;
}
