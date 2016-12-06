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
void getnext_rand();
void rannewc();
void showmaze();
/* Declare Tools Function */
//-------------------//
void looprow(int printer, char sym);

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
/*void getnext_rand()
{
	getch();
	//system("cls");
	static int current = 0;
    int getleft = fc_x - 1;
    int getright = fc_x + 1;
    int getup = fc_y - 1;
    int getdown = fc_y + 1;
    getleft = getleft < 0 ? 0 : getleft;
    getup = getup < 0 ? 0 : getup;
    getdown = getdown < 0 ? 0 : getdown;
    getright = getright < 0 ? 0 : getright;
    getleft = getleft > MAX_INROW ? 0 : getleft;
    getup = getup > MAX_INCOL ? 0 : getup;
    getdown = getdown > MAX_INROW ? 0 : getdown;
    getright = getright > MAX_INROW ? 0 : getright;
   // printf("GL = %d , GR = %d , GU = %d , GD = %d \n",getleft,getright,getup,getdown);
    printf("fc,x = %d fc_y = %d\n",fc_x,fc_y);
    //
    int nextran_x = 0;
    int nextran_y = 0;
    int no_x = rand() % 2;
    int no_y = rand() % 2;
    int case_u_d = rand() % 2;
    static int getlastud =0;
    static int getlastlr =0;
    printf("%d %d case %d \n",no_x,no_y,case_u_d);
    switch(case_u_d) {
    case 0: //go up 
  //  puts("Go ud \n");
        nextran_x = fc_x;
        switch(no_y)
        {
        	case 0:
        		if(getlastud == getup)
        		{
        			nextran_y = getdown;
        		getlastud = getdown;
				}
        		nextran_y = getup;
        		getlastud = getup;
        	//	puts("Go up Funcrion \n");
        		break;
        	case 1:
        		if(getlastud == getdown)
        		{
        			nextran_y = getup;
        		getlastud = getup;
				}
        		nextran_y = getdown;
        		getlastud = getdown;
        	//	puts("Go dpwm Funcrion \n");
        		break;
		}
        break;
    case 1:
    //	puts("Go < > Funcrion \n");
        nextran_y = fc_y;
        switch(no_x)
        {
        	case 0:
        		if(getlastlr == getleft)
        		{
        			nextran_x = getright;
        		getlastlr = getright;
				}
        	//	puts("Left");
        		nextran_x = getleft;
        		break;
        	case 1:
        		if(getlastlr == getright)
        		{
        			nextran_x = getleft;
        		getlastlr = getleft;
				}
        	//	puts("Right");
        		nextran_x = getright;
        		break;
		}
        break;
    }
    printf("%d %d\n",nextran_x,nextran_y);
    //getchar();
    if(nextran_x < MAX_INROW && nextran_x < MAX_INCOL && nextran_x >= 0 && nextran_y >= 0)
    {
    	if(nextran_x+1 != 2 && nextran_x-1 !=2 && nextran_y+1 != 2 && nextran_y-1 !=2 )
    	//puts("put new value");
    	{
    	fc_x = nextran_x;
        fc_y = nextran_y;
        maze[fc_x][fc_y] = 2;
        printf("Maze [%d][%d] = %d\n",fc_x,fc_y, maze[fc_x][fc_y]);	
		}
        
    }
    else
    {
    //	puts("put else fx");
        for(int r = 0; r < rows; r++) 
        {
            for(int c = 0; c < col; c++) 
            {
                if(maze[r][c] == 2)
                {
                    int tmpran = rand()%MAX_INROW;
                    if(tmpran % MAX_INROW-1 == 0)
                    {
                        r = rows;
                        fc_x = r;
                        fc_y = c;
                        break; // fetch new cursor in path to next rand
                    }
                }
            }
        }
    }
    current++;
    //printf("Current process %d",current);
}*/

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

void getnext_rand()
{
    printf("Current Cursor [%d][%d]\n",fc_x,fc_y);
    //system("SLEEP 0.05");
   // getch();
	
    system("cls");
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
    bool ismazefetch = false;
    while(ismazefetch != true)
    {
        
        ismazefetch = checkmaze();
    }
    puts("Start Initial maze");
   
}
