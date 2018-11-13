
//gcc -lform -lncurses -Wall hangman.c -o hangman
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include <ncurses.h>
#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <unistd.h>

int terminate(); //some functions that I separated from the main to avoid clutter and make testing easier.
void reload();
char enter, leave; //initial variable to start program
//=====================================================================

int main () {
//Initialization Part 1. Press [Enter] to progress to second initialization.
		srand(time(NULL));
		char array1[4][4] = {{'*', '*','*','*'}, {'*', '*','*','*'}, {'*', '*','*','*'}, {'*', '*','*','*'}};
		char array2[4][4] = {{'!', '@', '#', '$'},{'#', '$', '%', '^'},{'@', '^', '!', '&'},{'=', '%', '=', '&'}};

		int i;
		int j;
		int ent1, ent2, ent3, ent4;
		int running=1;
		int counter=0;
		initscr(); //creates a window/image that can be edited. printw, scanw, refresh, etc. are editing this 'window'


printw("Welcome to matching! To play, press [Enter]\n" );
 		while(running){
			reload();
			printw("    1   2   3   4\n\n");

			for(i=0; i<4; i++)
			{
				printw("%d", i+1);
				for(j=0; j<4; j++)
				{
					printw("   %c", array1[i][j]);
				}
			printw("\n\n");
			}

			// sleep(3);
			ent1=1;
			ent2=1;
			ent3=1;
			ent4=2;
			printw("Enter Coordinate 1 (x y): ");
			scanw("%1d", &ent1);
			scanw("%1d", &ent2);
			printw("Enter Coordinate 2 (x y): ");
			scanw("%1d", &ent3);
			scanw("%1d", &ent4);


			ent1 -=1;
			ent2 -=1;
			ent3 -=1;
			ent4 -=1;

			array1[ent1][ent2]= array2[ent1][ent2];
			array1[ent3][ent4]=array2[ent3][ent4];
//---------------------------------------------------- Initiallization Part 2
			//mvprintw(0, 35, "==========================="); //mvprintw prints a line at specific corrdinates.
			//mvprintw(1, 35, "        !!!!");

			reload();

			printw("    1   2   3   4\n\n");
			for(i=0; i<4; i++)
			{
				printw("%d", i+1);
				for(j=0; j<4; j++)
				{
					printw("   %c", array1[i][j]);
				}
			printw("\n\n");

			}
			if(array1[ent1][ent2]==array1[ent3][ent4]){
				if (ent1 != ent3 || ent2 != ent4) {
					printw("You got it! Nice!");
					terminate();
				}
			}

			counter++;
			if(counter>=5){
				printw("\nYou ran out of guesses. bruh ur stuppiddddd\n");
				terminate();
			}
			array1[ent1][ent2]= '*';
			array1[ent3][ent4]= '*';


		}


		terminate();
	return 0;
}



//=======================================================================================
//Other functions

void reload(){
	noecho(); //the terminal doesn't echo(type) what you enter. Kind of like when you input a password.
	enter = getch(); // get character typed. Like scanf

	while (enter != '\n') //if key typed is not entered, do nothing.
	 {
		refresh(); //refreshes the screen/window. Needed for ncurses function. prints won't appear unless the screen is refreshed.
		enter = getch();
	 }
	 move(0,0); //move cursor to top left of window (thats the starting point). The numbers are coordinates, but its (y,x) instead of (x,y)
	 int i;
	 int j;
	 for(i = 0; i < 100; i++){
		 for (j = 0; j < 100; j++) {
		 	printw(" ");
		 }
		 printw("\n");
	 }
	 move(0,0);
	 clrtoeol(); //clear the line (The welcome to hangman bla bla bla)
	 refresh();



}

int terminate () { //simple terminate function. Basically a duplicate of the enter in the first lines, but instead of initializing, it endwin (closes the window);

	mvprintw(30, 0, "Press [Q] to Quit\n" );
	leave = getch();
	leave = tolower(leave);
	refresh();
	while (leave != 'q')
	 {

		leave = getch();
		leave = tolower(leave);
	 }
	 endwin();
	 return 0;
}
