#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define MAX_STACK 500
#define monssize 10
#define prn printf
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define bomb O
#define explode +
#define PATH "highscore_ez.mazec"

void firstfetch();
void clearscreen();
void setpos(char pos);
void printmaze(int isspaces);
void fetchmaze(int isspaces);
void plantbomb(int posx,int posy);
void textcolor(int color);
void config();
void gohighscore_ez();
void movemonster();
void gameover();
void prnline(int num);
void mainofgame();
void randomspawn();
void printlevel(int numin);
int generate(int row,int col);
int playg();
/* Variable */
int originalrow = 8;
int originalcol =8;
int isset = 0;
char name[26];
int row = 8;
int col = 8;
int px = 1;
int py = 1;
int stat = 0;
int walker = 0;
int destination ;
int bombstatus =0;
int valueofspace =1;
int usersetrow = 0;
int usersetcol = 0;
int issetlevel = 0;
int curscore =0;
char character;
char wall = '#';
int x;
int y;
float hp;
/////////
char maze[50][200];
char lastwalk;
char monssymbol = 146;
int status =0;
int firstwalk = 0;
int tmpscore = 0;
/////////
/*STACK*/
int topx = 0;
int stackx[MAX_STACK];
int topy = 0;
int stacky[MAX_STACK];
int sp_peekx();
int sp_peeky();
////STACK FUNCTION ////
void readscore();
void writescore();
int popx();
void pushx(int value);
int isfullx();
int isemptyx();
int p_peekx();
int popy();
void pushy(int value);
int isfully();
int isemptyy();
int p_peeky();
//============//
struct scores
{
    char name[25];
    char namemid[25];
    char namehard[25];
    int highscore_ez;
    int highscore_mid;
    int highscore_hard;
} score;

/*TIME*/
time_t startmove,endmove;
double difmove;
double timeofplay = 30;
time_t startplay,endplay;
double difplay;
time_t start,end;
double dif;
time_t start2,end2;
double dif2;
time_t start3,end3;
double dif3;
/*TIME*/
struct monster
{
    int status;
    int posx;
    int posy;
} mons[monssize];
/*STRUCTURE OF MONS */
int main()
{
    int a=1,menu=1;
    char send='0';
    while(send != 13)
    {
        system("cls");
        printf("================================================================================\n");
        printf("                L.                                      L##Lffi#tL;i      f#i       ");
        printf("            EW:        ,ft                         tLLG##LF#;#L     .E#t        ");
        printf("       	E##;       t#E;                     ..        ,W#i     i#W,         ");
        printf("       	E##Et      t#E#;                   ;W,       j#E.     L#D.          ");
        printf("       	E#fE#f     t#E##t                 j##,      .D#j    :K#Wfff;        ");
        printf("       	E#t D#G    t#EfE#f               G###,     ,WK,     i##WLLLLt       ");
        printf("       	E#t  f#E.  t#E  D#G            :E####,    EG.        .E#L           ");
        printf("       	E#t   t#K: t#E   f#E.         ;W#  ##,  ,DKEl##fL#i   f#E:          ");
        printf("       	E#t    ;#W,t#E    t#K:       j###DW##, tLLG##LF#;#L    ,WW;         ");
        printf("       	E#t     :K#D#E     ;#W,     G##i,,G##,                  .D#;        ");
        printf("       	E#t      .E##E      :K#D  :K#K:   L##,                     tt       ");
        printf("       	..         G#E        .. ;##D.    L##,                              ");
        printf("                        fE           ,,,      ,,,                               ");
        printf("			                         ,                                      ");
        printf("\n");
        printf("\n");
        printf("\n\t\t\tUse Arrow Key Up & Down and Enter\n\n");
        printf("                               ");
        if(a == 1)
        {
            printf("===>   ");
            system("color a");
            menu=1;
        }
        printf("1.Play maze  ");
        if(a==1)
            printf(" <===");
        printf("\n\n");
        printf("                               ");
        if(a == 2)
        {
            printf("===>   ");
            system("color d");
            menu=2;
        }
        printf("2.Configure  ");
        if(a==2)
            printf(" <===");
        printf("\n\n");
        printf("                               ");
        if(a == 3)
        {
            printf("===>   ");
            system("color E");
            menu=3;
        }
        printf("3.How to play  ");
        if(a==3)
            printf(" <===");
        printf("\n\n");
        printf("                               ");
        if(a == 4)
        {
            printf("===>   ");
            system("color B");
            menu=4;
        }
        printf("4.Highscore  ");
        if(a==4)
            printf(" <===");
        printf("\n\n");
        printf("                               ");
        if(a == 5)
        {
            printf("===>   ");
            system("color c");
            menu=5;
        }
        printf("5.Exit      ");
        if(a==5)
            printf(" <===");
        printf("\n\n\n");
        switch(send = getch())
        {
        case KEY_DOWN:
            a++;
            //prn("\a");
            if(a > 5)
                a=5;
            break;
        case KEY_UP:
            a--;
            //prn("\a");
            if(a < 1)
                a=1;
            break;
        case 13:
            break;
        }
        if(send == 13)
        {
            prn("\a");
            break;
        }
    }
    switch(menu)
    {
    case 1:
        mainofgame();
        break;
    case 2:
        config();
        break;
    case 3:
        howtoplay();
        break;
    case 4:
        gohighscore_ez();
        break;
    case 5:
        exit(0);
    default:
        exit(0);
    }

    return 0;
}
void howtoplay()
{
    system("cls");
    prnline(2);
    prn("\n\n");
    prn("\t\t\tHow to Play :\n\n");
    prn("\t\tIn Maze they have monster Press Spacebar to place bomb \n\n\t\tIf you kill them you will got score\n\n");
    prn("\t\tUse Arrow key to move yourself \n\n\t\tThe First Character of yourname will be as you in game\n\n");
    prn("\t\tYou can use W A S D Key to move By \n\n\t\tW is UP A is Left S is DOWN and D is right\n\n");
    prn("\t\tIf you Finish Maze your time will be get as bonus\n\n\t\tEach Monster have 10 Points Bonus\n\n");
    prn("\t\tYour HP will decrease if you faild at bomb range \n\n\t\tHP left will be your score at the end\n\n");
    prn("\t\t\t Press Any key to Main menu");
    prn("\n\n");
    prnline(2);
    if(getch())
        main();
}
void delay(int milliseconds)
{
    long pause;
    clock_t now,then;
    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}
void config()
{
    int a=1,menu=1;
    char send='0';
    while(send != 27)
    {
        system("cls");
        prnline(3);
        prn("\n\t\t\tWelcome To Configure page\n");
        prnline(3);
        prn("\n\n Please Use Arrow to Select Adjust Settings Press Enter to Set \n\n");
        printf("\n\n");
        printf("                               ");
        if(a == 1)
        {
            printf("===>   ");
            menu=1;
        }
        printf("Configure Maze Level ");
        if(a==1)
            printf(" <===");
        printf("\n\n");
        printf("                               ");
        if(a == 2)
        {
            printf("===>   ");
            menu=2;
        }
        printf("Configure Monster Character ");
        if(a==2)
            printf(" <===");
        printf("\n\n");
        printf("                               ");
        if(a == 3)
        {
            printf("===>   ");
            menu=3;
        }
        printf("Configure Maze Space ");
        if(a==3)
            printf(" <===");
        printf("\n\n");
        printf("                               ");
        if(a == 4)
        {
            printf("===>   ");
            menu=4;
        }
        printf("Back to main Menu  ");
        if(a==4)
            printf(" <===");
        printf("\n\n");
        switch(send = getch())
        {
        case KEY_DOWN:
            a++;
            if(a > 4)
                a=4;
            break;
        case KEY_UP:
            a--;
            if(a < 1)
                a=1;
            break;
        case 13:
            break;
        }
        if(send == 13)
            break;
    }
    char tmps2=0;
    char tmps3=0;
    switch(menu)
    {
    case 1:
reenter:
        system("cls");
        char tmp1 =0;
        prnline(3);
        prn("\n\t\t\t Configure Maze Level\n");
        prnline(3);
        prn("\n\n\t\t\t Select Level \n\n");
        printf("\t\t\t Easy (1)\n\n\t\t\t Medium (2) \n\n\t\t\t Hard (3) \n\n \t\t\t Enter Number : ");
        scanf("%c",&tmp1);
        if(tmp1 <= 0 || tmp1 > 3 )
            goto reenter;
        else
        {
            switch(tmp1)
            {
            case '1':
                row = 12;
                usersetrow = 12;
                usersetcol = 12;
                timeofplay = 25;
                issetlevel = 1;
                break;
            case '2':
                row = 12;
                usersetrow =  12;
                usersetcol = 12;
                timeofplay = 75;
                issetlevel = 2;
                break;
            case '3':
                row = 13;
                usersetrow =13;
                usersetcol = 13;
                timeofplay = 120;
                issetlevel = 3;
                break;
            default:
                row = 12;
                usersetrow = 12;
                usersetcol = 12;
                timeofplay = 25;
                issetlevel = 1;
                break;
            }
            isset = 1;
        }
        prn("\n\n \t\t\t Updating  Settings");
        delay(2000);
        system("cls");
        config();
        break;
    case 2:
reenter2:
        tmps2=0;
        system("cls");
        prnline(3);
        prn("\n\t\t\t Configure Monster Character\n");
        prnline(3);
        prn("\n\n\t\t\t Select Monster Character\n\n");
        printf("\t\t\t %c (1)\n\n\t\t\t %c (2) \n\n\t\t\t %c (3) \n\n \t\t\t Enter Number : ",146,143,142);
        scanf("%c",&tmps2);
        switch(tmps2)
        {
        case '1':
            monssymbol = 146;
            break;
        case '2':
            monssymbol = 143;
            break;
        case '3':
            monssymbol = 142;
            break;
        default:
            goto reenter2;
        }
        prn("\n\n \t\t\t Updating  Settings");
        delay(2000);
        system("cls");
        config();
        break;
    case 3:
reenter3:
        tmps3=0;
        system("cls");
        prnline(3);
        prn("\n\t\t\t Configure Maze Space\n");
        prnline(3);
        prn("\n\n\t\t\t Select Size of Maze Space\n\n");
        printf("\t\t\t Close (1)\n\n\t\t\t Medium (2) \n\n\t\t\t Wide (3) \n\n \t\t\t Enter Number : ");
        scanf("%d",&tmps3);

        switch(tmps3)
        {
        case '1':
            valueofspace = 0;
            break;
        case '2':
            valueofspace = 1;
            break;
        case '3':
            valueofspace = 2;
            break;
        default:
            goto reenter3;
        }
        prn("\n\n \t\t\t Updating  Settings");
        delay(2000);
        system("cls");
        config();
        break;
    case 4:
        system("cls");
        main();
        break;
    }
}
void randomspawn()
{
    int possx[30] = {0};
    int possy[30] = {0};
    int walk = 0;
    for(int a = 1 ; a < row-1 ; a++)
    {
        for(int b = 1; b < col-1 ; b++)
        {
            if(maze[a][b] == '0' && walk < 30 && maze[a+1][b] != character && maze[a-1][b] != character && maze[a][b+1] != character && maze[a][b-1] != character)
            {
                possx[walk] = a;
                possy[walk] = b;
                // printf("%d %d \n",possx[walk],possy[walk]);
                walk++;
            }
        }
    }
    // puts("===");
    for(int a = 0 ; a < walk ; a++)
    {
        int tmp = rand()%30;
        mons[a].posx = possx[tmp];
        mons[a].posy = possy[tmp];
        mons[a].status = 1;
        //printf("%d %d\n",mons[a].posx,mons[a].posy);
    }
}

void movemonster()
{
    for(int a = 0 ; a < monssize ; a++)
    {
        if(mons[a].status == 0)
            continue;
        int randomway = rand()%4;
        switch (randomway)
        {
        case 0:
            if(maze[mons[a].posx-1][mons[a].posy] != wall)
            {
                mons[a].posx -=1;
                break;
            }
        case 1:
            if(maze[mons[a].posx+1][mons[a].posy] != wall)
            {
                mons[a].posx +=1;
                break;
            }
        case 2:
            if(maze[mons[a].posx][mons[a].posy-1] != wall)
            {
                mons[a].posy -=1;
                break;
            }
        case 3:
            if(maze[mons[a].posx][mons[a].posy+1] != wall)
            {
                mons[a].posy +=1;
                break;
            }

        default:
            break;
        }
        //   delay(1000);
    }
}
//////////////////////

void prnline(int num)
{
    for(int i = 0 ; i < num ; i++)
    {
        printf("================================================================================\n");
    }
}
void mainofgame()
{
    srand(time(NULL));
    system("cls");
    prnline(3);
    printf("\n\n\t\t\t Please Insert Player Name : ");
    scanf("%s",name);
    system("cls");
    prnline(3);
    prn("\t\t\t\tWelcome %s to Maze Survival\n\n");
    prnline(1);
    prn("Please Wait while Maze Generate Prepare for Escape !\n\n");
    prnline(1);
    delay(2800);
    character = name[0];
    playg();
}
int playg()
{
beganplayg:
    time(&startplay);
    system("cls");
    if(isset == 0)
    {
        row = originalrow;
        col = originalcol;
    }
    else
    {
        row = usersetrow;
        col = usersetcol;
    }
    system("color a");
    hp = 100;
    if(row %2 ==0)
        ++row;
    col = row;
    switch(issetlevel)
    {
    case 0:
    case 1:
        row*=2;
        row--;
        break;
    case 2:
        col*=2;
        row *= 1.5;
        col--;
        break;
    case 3:
        col*=2;
        row*=2;
        col--;
        row--;
        break;
     default:
        col*=2;
        row*=2;
        col--;
        row--;
        break;
    }
    px = 1;
    py = 1;
    x = 1;
    y = 1;
    firstfetch();
    pushx(px);
    pushy(py);
    puts("Please Wait Generating Maze");
    generate(row,col);
    fetchmaze(valueofspace);
    printf("\n\nPlease Check if Maze not have Exit \nPress R to Regenerate\nPress Enter to Play ... ");
    time(&startmove);
pointofchk:
    switch(getch())
    {
    case 'R':
    case 'r':
        goto beganplayg;
        break;
    case 13:
        break;
    default:
        goto pointofchk;
        break;
    }
    randomspawn();
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
    system("cls");
    time(&startplay);
    int isdone = 1;
    while(x!=0)
    {
        if(hp <= 0)
        {
            hp =0;
            break;
        }
        char key = '0';
        if(kbhit())
        {
            switch (key = getch())
            {
            case 'W':
            case 'w':
            case KEY_UP:
                --x;
                if(maze[x][y] == wall || maze[x][y] == monssymbol )
                    ++x;
                break;
            case 's':
            case 'S':
            case KEY_DOWN:
                ++x;
                if(maze[x][y] == wall || maze[x][y] == monssymbol )
                    --x;
                break;
            case 'a':
            case 'A':
            case KEY_LEFT:
                --y;
                if(maze[x][y] == wall || maze[x][y] == monssymbol )
                    ++y;
                break;
            case 'd':
            case 'D':
            case KEY_RIGHT:
                ++y;
                if(maze[x][y] == wall || maze[x][y] == monssymbol )
                    --y;
                break;
            case 32 :
                plantbomb(x,y);
                break;
            case 27 :
                main();
                break;
            default:
                break;
            }
            clearscreen();
            //system("cls");
            if((x == row-1 )&& (y== destination))
            {
                isdone = 0;
                break;
            }
        }
breakpoint:
        fetchmaze(valueofspace);
        clearscreen();
    }

    system("cls");
    px=1;
    py=1;
    gameover();
}
/* Stack Function  X */
int popx()
{
    int data;
    if(!isemptyx())
    {

        data = stackx[topx];
        topx = topx - 1;
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
        topx = topx + 1;
        stackx[topx] = value;
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
    if(topx == 0)
        return 1;
    else
        return 0;
}
int p_peekx()
{
    return stackx[topx];
}
int sp_peekx()
{
    return stackx[topx-1];
}
int sp_peeky()
{
    return stacky[topy-1];
}
/* End Stack Function X */
/* Stack Function  Y */
int popy()
{
    int data;
    if(!isemptyy())
    {
        data = stacky[topy];
        topy = topy - 1;
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
    if(topy == 0)
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
            maze[i][j] = wall;
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
    system("color a");
    difmove = difftime(time (&endmove),startmove);
    if(timeofplay - difplay == 0)
    {
        system("cls");
        gameover();
    }
    if((int)difmove == 1)
    {
        movemonster();
        time(&startmove);
    }
    int status = 0;
    static int isonbomb = 0;
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {

            if(maze[i][j] == '+')
            {
                printf("@");
                time (&end);
                dif = difftime (end,start);
                if(dif == 2)
                {
                    maze[i][j] = '0';

                    for(int a = i-1 ; a <= i+1 ; a++)
                    {
                        for(int b = j-1 ; b <= j+1 ; b++)
                        {
                            if(maze[a][b] == '0')
                            {
                                maze[a][b] = '!';
                            }
                        }
                    }
                    time (&start2);
                }
            }

            else if(mons[0].posx == i && j == mons[0].posy && mons[0].status == 1 && maze[i][j]  == '!' && i == x && j == y )
            {
                hp-=4;
                system("color c");
                printf("%c",character);
            }
            else if(mons[1].posx == i && j == mons[1].posy && mons[1].status == 1 && maze[i][j]  == '!' && i == x && j == y )
            {
                hp-=4;
                system("color c");
                printf("%c",character);
            }
            else if(mons[2].posx == i && j == mons[2].posy && mons[2].status == 1 && maze[i][j]  == '!' && i == x && j == y )
            {
                hp-=4;
                system("color c");
                printf("%c",character);
            }
            else if(mons[3].posx == i && j == mons[3].posy && mons[3].status == 1 && maze[i][j]  == '!' && i == x && j == y )
            {
                hp-=4;
                system("color c");
                printf("%c",character);
            }
            else if(mons[4].posx == i && j == mons[4].posy && mons[4].status == 1 && maze[i][j]  == '!' && i == x && j == y )
            {
                hp-=4;
                system("color c");
                printf("%c",character);
            }
            else if(mons[5].posx == i && j == mons[5].posy && mons[5].status == 1 && maze[i][j]  == '!' && i == x && j == y )
            {
                hp-=5;
                system("color c");
                printf("%c",character);
            }
            else if(mons[7].posx == i && j == mons[7].posy && mons[7].status == 1 && maze[i][j]  == '!' && i == x && j == y )
            {
                hp-=7;
                system("color c");
                printf("%c",character);
            }
            else if(mons[6].posx == i && j == mons[6].posy && mons[6].status == 1 && maze[i][j]  == '!' && i == x && j == y )
            {
                hp-=6;
                system("color c");
                printf("%c",character);
            }
            else if(mons[8].posx == i && j == mons[8].posy && mons[8].status == 1 && maze[i][j]  == '!' && i == x && j == y )
            {
                hp-=8;
                system("color c");
                printf("%c",character);
            }
            else if(mons[0].posx == i && j == mons[0].posy && mons[0].status == 1 && maze[i][j]  == '!')
            {
                mons[0].status = 0;
                curscore += 1;
                system("color c");
                bombstatus = 0;
            }
            else if(mons[9].posx == i && j == mons[9].posy && mons[9].status == 1 && maze[i][j]  == '!' && i == x && j == y )
            {
                hp-=9;
                system("color c");
                printf("%c",character);
            }
            else if(mons[1].posx == i && j == mons[1].posy && mons[1].status == 1 && maze[i][j]  == '!')
            {
                mons[1].status = 0;
                curscore += 1;
                system("color c");
                bombstatus = 0;
            }
            else if(mons[2].posx == i && j == mons[2].posy && mons[2].status == 1 && maze[i][j]  == '!')
            {
                mons[2].status = 0;
                curscore += 1;
                system("color c");
                bombstatus = 0;
            }
            else if(mons[3].posx == i && j == mons[3].posy && mons[3].status == 1 && maze[i][j]  == '!')
            {
                mons[3].status = 0;
                curscore += 1;
                system("color c");
                bombstatus = 0;
            }
            else if(mons[4].posx == i && j == mons[4].posy && mons[4].status == 1 && maze[i][j]  == '!')
            {
                mons[4].status = 0;
                curscore += 1;
                system("color c");
                bombstatus = 0;
            }
            else if(mons[5].posx == i && j == mons[5].posy && mons[5].status == 1 && maze[i][j]  == '!')
            {
                mons[5].status = 0;
                curscore += 1;
                system("color c");
                bombstatus = 0;
            }
            else if(mons[6].posx == i && j == mons[6].posy && mons[6].status == 1 && maze[i][j]  == '!')
            {
                mons[6].status = 0;
                curscore += 1;
                system("color c");
                bombstatus = 0;
            }
            else if(mons[7].posx == i && j == mons[7].posy && mons[7].status == 1 && maze[i][j]  == '!')
            {
                mons[7].status = 0;
                curscore += 1;
                system("color c");
                bombstatus = 0;
            }
            else if(mons[8].posx == i && j == mons[8].posy && mons[8].status == 1 && maze[i][j]  == '!')
            {
                mons[8].status = 0;
                curscore += 1;
                system("color c");
                bombstatus = 0;
            }
            else if(mons[9].posx == i && j == mons[9].posy && mons[9].status == 1 && maze[i][j]  == '!')
            {
                mons[9].status = 0;
                curscore += 1;
                system("color c");
                bombstatus = 0;
            }
            else if(maze[i][j] == '!' && i==x && j==y )
            {
                hp-=10;
                system("color c");
                printf("%c",character);
            }
            else if(maze[i][j] == '!' && 1 == difftime (time (&end2),start2))
            {
                for(int a = i-1 ; a <= i+1 ; a++)
                {
                    for(int b = j-1 ; b <= j+1 ; b++)
                    {
                        if(maze[a][b] == '!')
                        {
                            maze[a][b] = '0';
                        }
                    }
                }
                bombstatus=0;
            }

            else if(mons[0].posx == i && j == mons[0].posy && mons[0].status == 1)
            {
                printf("%c",monssymbol);
                // delay(25);
            }
            else if(mons[1].posx == i && j == mons[1].posy && mons[1].status == 1)
            {
                printf("%c",monssymbol);
                // delay(25);
            }
            else if(mons[2].posx == i && j == mons[0].posy && mons[2].status == 1)
            {
                printf("%c",monssymbol);
                // delay(25);
            }
            else if(mons[3].posx == i && j == mons[3].posy && mons[3].status == 1)
            {
                printf("%c",monssymbol);
                // delay(25);
            }
            else if(mons[4].posx == i && j == mons[4].posy && mons[4].status == 1)
            {
                printf("%c",monssymbol);
                // delay(25);
            }
            else if(mons[5].posx == i && j == mons[5].posy && mons[5].status == 1)
            {
                printf("%c",monssymbol);
                // delay(25);
            }
            else if(mons[6].posx == i && j == mons[6].posy && mons[6].status == 1)
            {
                printf("%c",monssymbol);
                // delay(25);
            }
            else if(mons[7].posx == i && j == mons[7].posy && mons[7].status == 1)
            {
                printf("%c",monssymbol);
                // delay(25);
            }
            else if(mons[8].posx == i && j == mons[8].posy && mons[8].status == 1)
            {
                printf("%c",monssymbol);
                // delay(25);
            }
            else if(mons[9].posx == i && j == mons[9].posy && mons[9].status == 1)
            {
                printf("%c",monssymbol);
                // delay(25);
            }
            else if(i == x && j == y)
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
    double tmpend = time(&endplay);
    difplay = (difftime (tmpend,startplay));
    printf(" HP : [%.f] Monster Killed : [%d] Timeleft : %.f \n",hp,curscore,timeofplay - difplay);

    // printf("================================================\n");
}
int generate(int row,int col)
{
    firstwalk = 0;
    //("PEEK %d %d %d %d\n",p_peekx(),p_peeky(),topx,topy);
    // getchar();
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
            // printf("Checker is %d\n",checker);
            // getchar();
        }
        if(checker == 0)
        {
            //printf("sp_peekx() = %d , y = %d \n",sp_peekx(),sp_peeky());
            //delay(2000);
            if(sp_peekx() > 0 && sp_peeky() > 0)
            {
                px = popx();
                py = popy();
                getpos();
            }
            else //if(sp_peekx() == 0 && sp_peeky() == 0 && topx == 1 )
            {
                status = 1;
                stackx[0] = 0;
                stacky[0] = 0;
            }
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
                //printf("px = %d =y = %d\n",px,py);
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

    firstwalk++;
    if(status == 1)
    {

        px=1;
        py=1;
        for(int s= 1 ; s < col ; s++)
        {
            s  = rand()%col;
            if(maze[row-2][s] == '0')
            {
                maze[row-1][s] ='0';
                destination = s;
                break;
            }
        }
        firstwalk = 0;
        status = 0;
        // ("PEEK %d %d %d %d\n",p_peekx(),p_peeky(),topx,topy);
        //  printf("Generate Maze Done\n");
    }
    else
        generate(row,col);
}
void clearscreen()
{
    HANDLE hOut;
    COORD Position;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}

void plantbomb(int posx,int posy)
{
    if(bombstatus == 0)
    {
        maze[posx][posy] = '+';
        bombstatus++;
        time (&start);
    }
}

void gameover()
{
    if(isset == 0)
    {
        row = originalrow;
        col = originalcol;
    }
    else
    {
        row = usersetrow;
        col = usersetcol;
    }
    int left = 0;
    for(int chk= 0 ; chk < monssize ; chk++)
    {
        if(mons[chk].status == 0)
            left++;
    }
    tmpscore = left*10;
    tmpscore += ((difplay)*100)*0.2;
    tmpscore += hp*50;
    walker = 0;
    destination =0 ;
    int i;
over:
    bombstatus = 0;
    randomspawn();
    prn("\a");
    system("color C");
    printf("                    *              )            (     \n");
    printf("   (       (     (  `          ( /(            )\\ )  \n");
    printf("   )\ )    )\\    )\\))(  (      )\\())(   (  (  (()/(  \n");
    printf("   (()/( ((((_)( ((_)()\\ )\\    ((_)\\ )\\  )\\ )\\  /(_)) \n");
    printf("   /(_))_)\\ _ )\\(_()((_|(_)     ((_|(_)((_|(_)(_))   \n");
    printf("   (_)) __ /_\\  |  \\/ || __|    / _ \\ \\ / /| __| _ \\  \n");
    printf("    | (_ |/ _ \\ | |\\/| | _|    | (_) \\ V / | _||   /  \n");
    printf("     \\___/_/ \\_\\|_|  |_|___|    \\___/ \\_/  |___|_|_\\  \n\n\n\n");
    // printf("\n\nDo you want to Play again ? : Y/N \n");
    prnline(2);
    delay(600);
    prn("\t\t\tMonster Killed x 10 ");
    delay(600);
    prn("= %d",left*=10);
    delay(600);
    prn("\n\n\t\t\tTime x 100 ");
    delay(600);
    prn("= %d",((int)(ceil((timeofplay - difplay)*100)*0.2)));
    delay(600);
    prn("\n\n\t\t\tHP Left x 50 ");
    delay(600);
    prn("= %d \n\n",(int)hp*50);
    delay(600);
    prn("\t\t\tYour Score is %d \n\n",tmpscore);
    if(tmpscore > score.highscore_ez)
    {
        readscore();
        prn("Congratulation ! You beat %s with Score : %d \n\n Difficulty : ",score.name,tmpscore);
        printlevel(issetlevel);
        if(issetlevel == 1)
        {
            strcpy(score.name,name);
            score.highscore_ez = tmpscore;
        }
        else if(issetlevel == 2)
        {
            strcpy(score.namemid,name);
            score.highscore_mid = tmpscore;
        }
        else if(issetlevel == 3)
        {
            strcpy(score.namehard,name);
            score.highscore_hard = tmpscore;
        }
        else
        {
            strcpy(score.name,name);
            score.highscore_ez = tmpscore;
        }
        writescore();
    }
    prn("\n\n");
    prnline(2);
    printf("\n\n Yes to Play again \n\n No to Quit and Go Back to main menu : Y/N >>> ");
    curscore = 0;
chkswitchover:
    switch (getch())
    {
    case 'Y':
    case 'y':
        system("cls");
        playg();
        break;
    case 'N':
    case 'n':
        main();
        break;
    default:
        goto chkswitchover;
        break;
    }
}
void writescore()
{
    FILE* fp;
    int count;
    remove(PATH); // Rewrite File at All
    fp = fopen(PATH,"w++");
    if(fp == NULL)
    {
        printf("Error in opening file");
    }
    else
    {
        fwrite(&score,sizeof(score),1,fp);
    }
    fclose(fp);
}
void readscore()
{

    FILE* fp;
    fp = fopen(PATH,"r");
    if(fp == NULL)
    {
        //printf("Error in opening file");
        fp = fopen(PATH,"w");
        score.highscore_ez = 0;
        score.highscore_hard = 0;
        score.highscore_mid = 0;
        strcpy(score.name,"Empty");
        strcpy(score.namemid,"Empty");
        strcpy(score.namehard,"Empty");
        fwrite(&score,sizeof(score),1,fp);
    }
    else
    {
        fread(&score, sizeof(score),1,fp);
    }
    fclose(fp);

}
/* End  Maze Function */
void printlevel(int numin)
{
    switch (numin)
    {
    case 0:
    case 1:
        printf("Easy");
        break;
    case 2:
        printf("Medium");
        break;
    case 3:
        printf("Hard");
        break;
    default:
        break;
    }
}
void gohighscore_ez()
{
    system("cls");
    prnline(3);
    readscore();
    printf("\n\n\t\t\t Current Highscore : %d \n\n\t\t\t By : %s \n\n\t\t\t Difficulty :  ",score.highscore_ez,score.name);
    printlevel(1);
    prn("\n\n");
    prnline(1);
    printf("\n\n\t\t\t Current Highscore : %d \n\n\t\t\t By : %s \n\n\t\t\t Difficulty :  ",score.highscore_mid,score.namemid);
    printlevel(2);
    prn("\n\n");
    prnline(1);
    printf("\n\n\t\t\t Current Highscore : %d \n\n\t\t\t By : %s \n\n\t\t\t Difficulty :  ",score.highscore_hard,score.namehard);
    printlevel(3);
    prn("\n\n");
    prnline(3);
    prn("\n\n\n\t\t\t Press Any Key to back to main menu ...\n\n\n");
    if(getch())
    {
        main();
    }
}
//End Coding
