#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define MAX_STACK 500
//============//


/* Stack */
int popx();
void pushx(int value);
int isfullx();
int isemptyx();
int p_peekx();
//
int popy();
void pushy(int value);
int isfully();
int isemptyy();
int p_peeky();

/* End Stack */
//============//
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
/* Declare Maze Function */
void firstfetch();
int playg();
void clearscreen();
void setpos(char pos);
void printmaze(int isspaces);
void fetchmaze(int isspaces);
int generate(int row,int col);
/* End Declare Maze Function */
//============//

/* Declare Size */
int row = 11;
int col = 11;
int px = 1;
int py = 1;
int stat = 0;
int walker = 0;
int destination;
/*Declare Player pointer*/
char character;
int x;
int y;
int hp;
/* End Declare Size */
//============//

/* Declare Variable */

int topx = 0;
int stackx[MAX_STACK];
int topy = 0;
int stacky[MAX_STACK];
char maze[50][200];
char lastwalk;
int status =0;
int firstwalk = 0;
/* End DeclareVariable */

//============//
int main()
{
   // printf("TopX = %d\n",topx);
    srand(time(NULL));
    char name[26];
    printf("Input Name : ");
    scanf("%s",&name);
    character = name[0];
    playg();
    return 0;
}
int playg()
{

    printf("Input Maze Size : ");
    scanf("%d",&row);
    printf("%d",row);
    if(row %2 ==0)
        ++row;
    col = row;
    row*=2;
    row--;
    //printf("row = %d col = %d\n",row,col);
    px = 1;
    py = 1;
    firstfetch();
    pushx(px);
    pushy(py);
    //generate(row,col);
     generate(row,col);
       printf("TopX = %d\n",topx);
  //  generate(row,col);
  //  generate(row,col);
    // printmaze(1);
    // Done generate //
    void randomstart()
    {
        int start = rand()%col;
        if(maze[1][start] == '0')
        {
            x = 1;
            y = start;
        }

        else
            randomstart();
    }
    randomstart();
    int isdone = 1;
    while(x!=0)
    {
          // printf("TopX = %d\n",topx);
        printf("[%d][%d]\n",row-1,destination);
        char key = getch();
        switch (key)
        {
        case 'W':
        case 'w':
        case KEY_UP:
            --x;
            if(maze[x][y] == '#')
                ++x;
            break;
        case 's':
        case 'S':
        case KEY_DOWN:
            ++x;
            if(maze[x][y] == '#')
                --x;
            break;
        case 'a':
        case 'A':
        case KEY_LEFT:
            --y;
            if(maze[x][y] == '#')
                ++y;
            break;
        case 'd':
        case 'D':
        case KEY_RIGHT:
            ++y;
            if(maze[x][y] == '#')
                --y;
            break;
        default:
            break;
        }
        printf("HP : [%d]\n",hp);
        for(int i = 0 ; i < 10 ; i++)
        {
            printf("[STACKX] = %d [STACKY] = %d TOPXY = %d\n",stackx[i],stacky[i],topx);
        }
       // ("PEEK %d %d %d %d\n",p_peekx(),p_peeky(),topx,topy);
        //clearscreen();
        system("cls");
        if((x == row-1 )&& (y== destination))
        {
            isdone = 0;
            break;
        }
        else
            fetchmaze(1);
    }
    system("cls");
    printf("Do you want to Play again ? : Y/N \n");
    char st = getch();
    switch (st)
    {
    case 'Y':
    case 'y':
       /* system("cls");
         for(int i = 0 ; i < MAX_STACK ; i++)
        {
            stackx[i] = 0;
            stacky[i]= 0;
        }
        firstwalk = 0;
        ("PEEK %d %d %d %d\n",p_peekx(),p_peeky(),topx,topy);*/
        return playg();
        break;
    case 'N':
    case 'n':
        exit(0);
    }
}
/* Stack Function  X */
int popx()
{
    int data;
    if(!isemptyx())
    {

        data = stackx[topx];
        stackx[topx] = 0;
      //  printf("POP = %d\n",data);
        topx = topx - 1;
        // printf("will pop x = %d ",data);
        return data;
    }
    else
    {
        printf("ERROR Underflow POPX = %d Ternimate Program",topx);
        exit(0);
    }
}
void pushx(int value)
{

    if(!isfullx())
    {
        // maze[px][py] ='0';
        topx = topx + 1;
        stackx[topx] = value;
        //printf("Pushx in = %d\n",value);
    }
    else
    {
        printf("ERROR Overflow  Ternimate Program");
        exit(0);
    }
}
int isfullx()
{
    if(topx == MAX_STACK)
        return 1;
    else
        return 0;
}
int isemptyx()
{
    if(topx == -1)
        return 1;
    else
        return 0;
}
int p_peekx()
{
    return stackx[topx];
}
/* End Stack Function X */
/* Stack Function  Y */
int popy()
{
    int data;
    if(!isemptyy())
    {
        data = stacky[topy];
        stacky[topy] = 0;
        topy = topy - 1;
       // printf("POP = %d\n",data);
        return data;
    }
    else
    {
        printf("ERROR Underflow POPY Ternimate Program");
        exit(0);
    }
}
void pushy(int value)
{

    if(!isfully())
    {
        topy = topy + 1;
        stacky[topy] = value;
        //printf("Pushy in = %d\n",value);

    }
    else
    {
        printf("ERROR Overflow Ternimate Program");
        exit(0);
    }
}
int isfully()
{
    if(topy == MAX_STACK)
        return 1;
    else
        return 0;
}
int isemptyy()
{
    if(topy == -1)
        return 1;
    else
        return 0;
}
int p_peeky()
{
    return stacky[topy];
}
/* End Stack Function Y */
/*  Maze Function */
void firstfetch()
{
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            maze[i][j] = '#';
        }
    }

    maze[1][1] = '0';

    // maze[row-1][col-1] = '0';
}
void printmaze(int isspaces)
{
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            //	if(maze[i][j] != '0')
            printf("%c",maze[i][j]);
            //   else
            //	printf(" ");
            for(int space = 1 ; space <= isspaces ; space++)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("================================================\n");
}
void fetchmaze(int isspaces)
{
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            if(i == x && j == y)
                printf("%c",character);
            else if(maze[i][j] != '0')
                printf("%c",maze[i][j]);
            else
                printf(" ");
            for(int space = 0 ; space < isspaces ; space++)
            {
                printf(" ");
            }

        }
        printf("\n");
    }
   // printf("================================================\n");
}
int generate(int row,int col)
{
  //  getchar();
    //printf("Current Cursor = (%d,%d)\n",px,py);
    stat = 0;
    char stackpossible[4]= {'0'};
    //Get Possible Path
    void getpos()
    {
        walker = 0;
        if(px+2 < row && maze[px+2][py] != '0')
        {
            stackpossible[walker] = 'D';
            walker++;
        }
        if(px-2 >= 0 && maze[px-2][py] != '0')
        {
            stackpossible[walker] = 'U';
            walker++;
        }
        if(py-2 >= 0 && maze[px][py-2] != '0')
        {
            stackpossible[walker] = 'L';
            walker++;
        }
        if(py+2 < col && maze[px][py+2] != '0')
        {
           // printf("Cursor = (%d,%d) = %c\n",px,py+2,maze[px][py+2]);
           // printf("%d\n",py+2 <= col && maze[px+2][py] != '0');
            stackpossible[walker] = 'R';
            walker++;
        }
        int checker = 0;
        for(int i = 0,j = 0; i  < 4 ; i++)
        {
            if(stackpossible[i] == 'L' || stackpossible[i] == 'R' || stackpossible[i] == 'D' || stackpossible[i] == 'U')
                checker++;

        }
        if(checker == 0)
        {
            px = popx();
            py = popy();
            if(p_peekx() == 1 && p_peeky() == 1 && firstwalk != 0 )
                status = 1;
            else
                getpos();
        }
    }


        getpos();
        char tmpchar[walker];
        for(int i = 0,j = 0; i  < 4 ; i++)
        {
            tmpchar[j] = '0';
        }
        for(int i = 0,j = 0; i  < 4 ; i++)
        {
            if(stackpossible[i] != '0')
            {
                tmpchar[j] = stackpossible[i];
            //    printf("Possible Direction = %c \n",tmpchar[j]);
                j++;
            }
        }
        int numwalk=0;
        if(walker != 0)
        {
            numwalk = rand()%walker;
            switch (tmpchar[numwalk])
            {
            case 'D':
                if(maze[px+2][py] != '0')
                {

             //       printf("px = %d =y = %d\n",px,py);
                    maze[px+1][py] ='0';
                    maze[px+2][py] ='0';
                    px+=2;
                    pushx(px);
                    pushy(py);
                    break;
                }

            case 'U':
                if(maze[px-2][py] != '0')
                {

                    maze[px-1][py] ='0';
                    maze[px-2][py] ='0';
                    px-=2;
                    pushx(px);
                    pushy(py);
                    break;
                }

            case 'R':
                if(maze[px][py+2] != '0')
                {
                    //py+=2;
            //        printf("px = %d =y = %d\n",px,py);
                    maze[px][py+1] ='0';
                    maze[px][py+2] ='0';
                    py+=2;
                    pushx(px);
                    pushy(py);
                    break;
                }

            case 'L':
                if(maze[px][py-2] != '0')
                {
                    maze[px][py-1] ='0';
                    maze[px][py-2] ='0';
                    py-=2;
                    pushx(px);
                    pushy(py);
                    break;
                }

            }
        }

      //  printf("Direction = %c \n",tmpchar[numwalk]);

        // move

        //move
        firstwalk++;
       // printf("Firstwalk = %d\n",firstwalk);
       // printf("Peek x = %d Peek y = %d\n",p_peekx(),p_peeky());
        for(int i = 0 ; i < topx ; i++)
        {
            printf("[STACKX] = %d [STACKY] = %d TOPXY = %d\n",stackx[i],stacky[i],topx);
        }
       // printf("Current Cursor = (%d,%d)\n",px,py);



    // printmaze(1);
    if(status == 1)
    {

        px=1;
        py=1;
        int rdof = rand()%row;
        if(maze[row-2][rdof] == '0')
        {
            maze[row-1][rdof] ='0';
            destination = rdof;
        }
        //getchar();
        // system("cls");
        /*
        for(int s ; s < MAX_STACK; s++)
        {
            stackx[s] = 0;
            stacky[s] = 0;*/

        //}
        for(int i = 0 ; i < topx ; i++)
        {
            printf("[STACKX] = %d [STACKY] = %d TOPXY = %d\n",stackx[i],stacky[i],topx);
        }
        firstwalk = 0;
        ("PEEK %d %d %d %d\n",p_peekx(),p_peeky(),topx,topy);
        printf("Generate Maze Done\n");
    }
    else
         generate(row,col);
    //move


}
//	randoms();
void clearscreen() //MY TEACHER SUGGESTED ME THIS CODE TO "CLEAR" THE SCREEN
{
    HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}
/* End  Maze Function */
