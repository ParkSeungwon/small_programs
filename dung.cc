#include <ncurses.h>
#include <pthread.h>
#include <signal.h>

#define MAX_BALLS   10

#define getrandom( min, max ) ((rand() % (int)(((max) + 1) - (min))) + (min))

typedef struct { int x, y ; } POSITION ;
POSITION ball_pos[MAX_BALLS] ;
int win_left, win_right, win_top, win_bottom ;

int delay = 50000 ;


void sig_handler()
{
    printf("Ctl-C pressed to stop the process! \n");
    refresh();
    endwin();
    exit(0) ;

}

void ball_bounce(int ch)
{
    int number = ch;
    char blank = ' ';
    POSITION delta ;
    int cx, cy, old_x, old_y ;


    cx = getrandom(2,win_right-2);
    cy = getrandom(2,win_bottom-2);
    delta.x = getrandom(-2,2);
    delta.y = getrandom(-2,2);

    while (1) {
        // Moving

        move(cy, cx) ;
        attron(A_BOLD);
        printw("%c", ch) ;
        attroff(A_BOLD);
        refresh();
        usleep(delay);

        // Wall Bound
        if(cy <= win_top+1 || cy >= win_bottom-1) {
            delta.y = -1*delta.y ;
            beep() ;
        }
        if(cx <= win_left+1 || cx >= win_right-1) {
            delta.x = -1*delta.x ;
            beep();
        }

        old_x = cx ;
        old_y = cy ;
        move(old_y, old_x) ;
        printw("%c", blank);
  // next position
        cx = cx + delta.x ;
        cy = cy + delta.y ;
    }
}



int main()
{
    int ch, i=0 ;
    int sz_row, sz_col ;
    char buffer[100] ;
    pthread_t thread[MAX_BALLS] ;


    initscr() ;
    keypad(stdscr, TRUE) ;
    noecho();
    curs_set(0) ;
    srand(234567);


    if (signal(SIGINT, sig_handler) == SIG_ERR) {
        printf("\ncan't catch SIGINT\n") ;
        exit(0) ;
    }


    getmaxyx(stdscr, sz_row, sz_col);
    move(0,0);
    sprintf(buffer, "> the size of row and col : %3d %3d \n", sz_row, sz_col);

    win_left = 0 ; win_top = 0 ;
    win_right = sz_col-1 ; win_bottom = sz_row-1 ;

    ch = getch() ;
    if (ch != 'q') {
        ball_bounce('A') ;
    }

    refresh();
    endwin() ;
}
