#include "gamePlay.h"
using namespace std;
#define pointSnake 254 
#define MAX 100
#define initLength 3
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

struct point{
    int x;
    int y;
};
point snake[MAX];

void gotoXY(short int x, short int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void displaySnake(){
    for (int i=0;i<initLength;i++){
        gotoXY(snake[i].x, snake[i].y);
        cout<< (char)pointSnake;
    }
}

void initSnake(){
    snake[0].x=5;
    snake[1].x=6;
    snake[2].x=7;
    snake[0].y=snake[1].y=snake[2].y=1;
    displaySnake();
}

void moveSnake(){
    int direction=DOWN;
    while(1){
        for (int i=initLength-1;i>=1;i--){
            snake[i]=snake[i-1];       
        }
        switch (direction)
        {
        case UP:
            snake[0].y--;
            break;
        
        case DOWN:
            snake[0].y++;
            break;

        case LEFT:
            snake[0].x--;
            break;

        case RIGHT:
            snake[0].x++;
        
        default:
            break;
        }
       
        system("cls");
        displaySnake();
        if(kbhit()){
        direction=inputKeyboard();
        }
        Sleep(500);
    }
}

int inputKeyboard(){
    int direction;
    char keyPress=getch();
    int asciiValue=keyPress;
    if (asciiValue==119){
        direction=UP;
    }
    else if (asciiValue==97){
        direction=LEFT;
    }
    else if (asciiValue==100){
        direction=RIGHT;
    }
    else if (asciiValue==115){
        direction=DOWN;
    }
    return direction;
}

