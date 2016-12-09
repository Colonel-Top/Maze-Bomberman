//--------------------------------------------------------------------------
//----*******---*******---*---------*******---*------*---******---*---------
//----*---------*-----*---*---------*-----*---*-*----*---*--------*---------
//----*---------*-----*---*---------*-----*---*---*--*---*--------*---------
//----*---------*-----*---*---------*-----*---*----*-*---******---*---------
//----*---------*-----*---*---------*-----*---*-----**---*--------*---------
//----*---------*-----*---*---------*-----*---*------*---*--------*---------
//----*******---*******---*******---*******---*------*---******---*******---
//--------------------------------------------------------------------------

/* Calling header */
//-------------------//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

/* Define */
//-------------------//
#define MAX_INROW 10 // 50 Character
#define MAX_INCOL 10 // 50 Character

/* Define Boolean*/
//-------------------//
typedef int bool;
#define true 1
#define false 0

/* Declare Global Variable & Function */
//-------------------//

int rows = MAX_INROW, col = MAX_INCOL;
int maze[MAX_INROW][MAX_INCOL];

int fc_x =0;
int fc_y = 0;
#define SETM2 maze[fc_x][fc_y]=2;
#define SETM1 maze[fc_x][fc_y]=1;
void fetchmaze (int mazesize[rows][col]);
void fetchmain();
void fetchhighscore();
void clearmaze();
int checkmaze();
void mazeinitial();
void rannewc();
void showmaze();
/* Declare Tools Function */
//-------------------//
void looprow(int printer, char sym);

// Declare Stack Function;
int top = -1;
int MAXSIZE = 100;
int stackx[100];
int stacky[100];
void push(int x,int y);
void pop();
void push(int x,int y)
{
	top = top+1;
	stackx[pop] = x;
	stacky[pop] = y;
}
void pop()
{
	top =  top-1;
}
/* Main Section */
//-------------------//
int main(int argc, char* argv[])
{
	srand(time(NULL));
//	puts("Donetest");
    fetchmaze(maze);
    return 0;
}

void looprow(int printer, char sym)
{
    for(int tmp = 0; tmp < printer; tmp++)
        printf("%c", sym);
}

void fetchmain()
{
    looprow(40, '*');
}
void clearmaze()
{
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < col; c++) {

            maze[r][c] = 0;
        }
    }
}
int checkmaze()
{
    bool mazestatus = true;
    while(mazestatus != false) {
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < col; c++) {

                if(maze[r][c] == 0) {
                    mazestatus = false; // return 0 if false
                    printf("Maze [%d][%d] still  reach 0 \n",r,c);
                    r = rows-1;
                }
            }
        }
    }
    if(mazestatus == true)
    	puts("ITS TRUE");
    return mazestatus;
}

void rannewc()
{

    for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < col; c++)
            {
                if(maze[r][c] == 2)
                {
                    int tmpran = rand()%30;
                    if(tmpran %31  == 0)
                    {
                        fc_x = r;
                        fc_y = c;
                        break; // fetch new cursor in path to get new next rand
                    }
                }
            }
        }
}

void mazeinitial()
{
    
}

void showmaze()
{
    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < col; c++)
        {
            printf("%d ",maze[r][c]);
        }
        printf("\n");
    }
}
void fetchmaze(int mazesize[rows][col])
{

    showmaze();
	puts("Fetching maze");
    clearmaze();
    int tmprow = rand() % rows;
    int tmpcol = rand() % col;
    //mazesize[tmprow][tmpcol] = ; // ramdom start
    fc_x = tmprow;
    fc_y = tmpcol;
    printf("fc_x = %d , fc_y = %d\n",fc_x,fc_y);
    //getch();
    puts("Start Initial maze");
	mazeinitial();
}
