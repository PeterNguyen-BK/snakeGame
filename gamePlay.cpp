#include "gamePlay.h"
using namespace std;

point snake[MAX];
int initLength=3;

void gotoXY(short int x, short int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void displaySnake(point endPoint){
    for (int i=0;i<initLength;i++){
        gotoXY(snake[i].x, snake[i].y);
        cout<< (char)pointSnake;
    }
    gotoXY(endPoint.x, endPoint.y);
    cout<<" ";
}

void initSnake(){
    snake[0].x=5;
    snake[1].x=6;
    snake[2].x=7;
    snake[0].y=snake[1].y=snake[2].y=5;
}

point moveSnake(int direction){
    point endPoint=snake[initLength-1];
   
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
    return endPoint; 
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

void initFrame(){
    for (int x=LEFT_WALL;x<=RIGHT_WALL;x++){    //Initialize above wall
        gotoXY(x,ABOVE_WALL);
        cout<<(char)220;
    }
    for (int y=ABOVE_WALL+1;y<=BOTTOM_WALL;y++){  //Initialize left wall
        gotoXY(LEFT_WALL,y);
        cout<<(char)221;
    }
    
    for (int y=ABOVE_WALL+1;y<=BOTTOM_WALL;y++){  //Initialize left wall
        gotoXY(RIGHT_WALL,y);
        cout<<(char)221;
    }
     for (int x=LEFT_WALL;x<=RIGHT_WALL;x++){    //Initialize bottom wall
        gotoXY(x,BOTTOM_WALL);
        cout<<(char)223;
    }
}

bool checkImpact(){
    if (snake[0].x==LEFT_WALL || snake[0].x==RIGHT_WALL){
        initLength=3;
        return true;
    }
    else if (snake[0].y==ABOVE_WALL || snake[0].y==BOTTOM_WALL){
        initLength=3;
        return true;
    }
    else return false;
}

point initFood(){
    point food;
    srand(time(NULL));
    food.x=rand() % (RIGHT_WALL-LEFT_WALL-2) + (LEFT_WALL+1);
    food.y=rand() % (BOTTOM_WALL-ABOVE_WALL-2) + (ABOVE_WALL+1);
    gotoXY(food.x, food.y);
    cout<<"#";
    return food;
}

bool snakeEat(point food){
    if (snake[0].x==food.x && snake[0].y==food.y){
        initLength++;
        return true;   
    }
    else return false;
}

