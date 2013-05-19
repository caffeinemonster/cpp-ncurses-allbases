//all your base are blong to us!!!
//console ncurses screen saver
//compile using g++ allbases.cpp -o bases -lncurses
#include <cstdlib>
#include <ncurses.h>
#include <time.h>
int main(){
	int cp;
	initscr();	  /* Start curses mode 		  */
   	noecho();         // dont display input
   	cbreak();         // don't interrupt for user input
   	timeout(0);     // wait 500ms for key press
	curs_set(0);	  // dont display cursor
	srand (time(NULL)); // seed rnumber generator
        start_color();			/* Start color 			*/
	// define colour pairs
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
		cp = rand() % 14 + 1; // generate colour pair variable (number between 1 and 14)
		attron(COLOR_PAIR(cp)); // enable colour pair
		int vx, vy;         // create some variables to store string location
		vx = rand() % COLS; // assign random number to vx
		vy = rand() % LINES; // assign random number to vy
		keypad(stdscr, TRUE); // capture function keys f1 f2 etc
		mvprintw(vy, vx, "all your base are belong to us!!!"); // print message to screen
		attroff(COLOR_PAIR(cp));	// disable colour pair
	        refresh();	    // refresh output on the screen 
		int c;		    // define variable to store key pressed
		c = getch();        // store key pressed in variable c
		if (c==113){break;} // break if 'q' is pressed
		if (c==27){break;} // break if 'escape' is pressed
		if (c==32){break;} // break if 'SPACE' is pressed
		if (c==13){break;} // break if 'carrige return' is pressed
		if (c==10){break;} // break if 'linefeed'
	}while(1==1);
        endwin();			//End curses mode
	return 0;
}
