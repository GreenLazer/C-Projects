//Louie Kotler
//gcc -lform -lncurses -Wall hangman.c -o hangman
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include <ncurses.h>
#include <unistd.h>
#include <ctype.h>

void reload();

int terminate();

//=====================================================================


int main () {
//Initialization Part 1. Press [Enter] to progress to second initialization.

	initscr(); //creates a window/image that can be edited. mvprintw, scanw, refresh, etc. are editing this 'window'
  char enter;
	mvprintw(0,0,"Matching Game\n" );
	noecho(); //the terminal doesn't echo(type) what you enter. Kind of like when you input a password.
  enter = getch(); // get character typed. Like scanw

	while (enter != '\n') //if key typed is not entered, do nothing.
	 {
	 	refresh(); //refreshes the screen/window. Needed for ncurses function. prints won't appear unless the screen is refreshed.
		enter = getch();
	 }
	 move(0,0); //move cursor to top left of window (thats the starting point). The numbers are coordinates, but its (y,x) instead of (x,y)
	 clrtoeol(); //clear the line (The welcome to hangman bla bla bla)
	 refresh();
//---------------------------------------------------- Initiallization Part 2
	mvprintw(0,0,"===========================\n"); //mvmvprintw prints a line at specific corrdinates.
	mvprintw(1,0,"        Matching Game\n");
	mvprintw(2,0,"===========================\n\n");
  refresh();
//---------------------------------------------------
  	char array1[4][4] = {{'*', '*','*','*'}, {'*', '*','*','*'}, {'*', '*','*','*'}, {'*', '*','*','*'}};


    //char array2[4][4] = {{'!', '@', '#', '$'},{'#', '$', '%', '^'},{'@', '^', '!', '&'},{'=', '%', '=', '&'}};

//--------------------------------------------------------------------------------------------------

		int x, y, z, count;
		x = 0;
		count = 0;
		char arr[16] = {'!', '@', '#', '$','#', '$', '%', '^','@', '^', '!', '&','=', '%', '=', '&'};
        char arr2[16] = {'0', '0', '0', '0','0', '0', '0', '0','0', '0', '0', '0','0', '0', '0', '0'};
        srand(time(NULL));
        while (x < 16){

        	int r = rand()%16;
        	if(arr[r] != '0'){
        		arr2[x] = arr[r];
        		arr[r] = '0';
        		x++;
        	}

        }
		char array2[4][4] ={{'0', '0', '0', '0'},{'0', '0', '0', '0'},{'0', '0', '0', '0'},{'0', '0', '0', '0'}};
		for (y = 0; y < 4; y++){
			for (z = 0; z < 4; z++){
				array2[y][z] = arr2[count];
				count++;
			}
		}

//--------------------------------------------------------------------------------------------------

  	//int i;
  	//int j;
  	//unsigned int ent1, ent2, ent3, ent4;
  	int running=1;
  	int counterfull=0;

  	while(running){
    int ent1=0, ent2=0, ent3=0, ent4=0;
    initscr();

    reload();

    mvprintw(0,0,"===========================\n"); //mvmvprintw prints a line at specific corrdinates.
  	mvprintw(1,0,"        Matching Game\n");
  	mvprintw(2,0,"===========================\n\n");
    refresh();

    mvprintw(4,0,"\n");
  	mvprintw(5,0,"    1   2   3   4\n\n");
    refresh();

  	/*for(i=0; i<4; i++)
  	{
  		mvprintw("%d", i+1);
  		for(j=0; j<4; j++)
  		{
  			mvprintw("   %c", array1[i][j]);
  		}
  	mvprintw("\n\n");
  	}
    */

    mvprintw(8,0,"1   %c   %c   %c   %c", array1[0][0], array1[0][1], array1[0][2], array1[0][3]);
    mvprintw(11,0,"2   %c   %c   %c   %c", array1[1][0], array1[1][1], array1[1][2], array1[1][3]);
    mvprintw(14,0,"3   %c   %c   %c   %c", array1[2][0], array1[2][1], array1[2][2], array1[2][3]);
    mvprintw(17,0,"4   %c   %c   %c   %c", array1[3][0], array1[3][1], array1[3][2], array1[3][3]);
    refresh();

  	//sleep(3);

  	mvprintw(20,0,"Enter Coordinate 1 (x y): ");
    echo();
    refresh();
  	scanw("%d%d", &ent1,&ent2);
    refresh();
    noecho();

    refresh();

  	mvprintw(21,0,"Enter Coordinate 2 (x y): ");
    echo();
    refresh();
  	scanw("%d%d", &ent3,&ent4);

    refresh();

    noecho();







  	ent1 -=1;
  	ent2 -=1;
  	ent3 -=1;
  	ent4 -=1;



    memcpy(&array1[ent1][ent2], &array2[ent1][ent2], 1);
    memcpy(&array1[ent3][ent4], &array2[ent3][ent4], 1);


  //sleep(3);
    mvprintw(5,0,"    1   2   3   4\n\n");




  	/*for(i=0; i<4; i++)
  	{
  		mvprintw("%d", i+1);
  		for(j=0; j<4; j++)
  		{
  			mvprintw("   %c", array1[i][j]);
  		}
  	mvprintw("\n\n");

  }*/

  mvprintw(8,0,"1   %c   %c   %c   %c", array1[0][0], array1[0][1], array1[0][2], array1[0][3]);
  mvprintw(11,0,"2   %c   %c   %c   %c", array1[1][0], array1[1][1], array1[1][2], array1[1][3]);
  mvprintw(14,0,"3   %c   %c   %c   %c", array1[2][0], array1[2][1], array1[2][2], array1[2][3]);
  mvprintw(17,0,"4   %c   %c   %c   %c", array1[3][0], array1[3][1], array1[3][2], array1[3][3]);


  echo();
  refresh();



  	if(array1[ent1][ent2]==array1[ent3][ent4]){
  		if (ent1 != ent3 || ent2 != ent4) {
				running = 0;
  			mvprintw(4,0,"You got it! Nice!\n");
  			//terminate();
				//endwin();
				system("clear");


  		}
  	}
  //here is refresh
  	array1[ent1][ent2]= '*';
  	array1[ent3][ent4]= '*';

  	counterfull++;
		mvprintw(3,0, "Guesses Left: %d", 5-counterfull);
  	if(counterfull>=5){
			running = 0;
  		mvprintw(4,0,"\nYou ran out of guesses, bruh ur stuppiddddd\n");
			system("clear");



  	}
    refresh();

  }


  	return 0;
  }





//=======================================================================================
//Other functions
void reload(){
  char enter;
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
  char leave;
	mvprintw(22,0,"Press [Q] to Quit\n" );
	leave = getch();
	leave = tolower(leave);
	refresh();
	while (leave == 'q')
	 {

		leave = getch();
		leave = tolower(leave);
		endwin();
	 }
	 endwin();

	 return 0;
}
