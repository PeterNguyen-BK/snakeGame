#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <time.h>
using namespace std;
#define pointSnake 254 
#define MAX 100
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define ABOVE_WALL 2
#define BOTTOM_WALL 15
#define LEFT_WALL 2
#define RIGHT_WALL 60 



struct point{
    int x;
    int y;
};


void gotoXY(short int x, short int y);
void initSnake();
void displaySnake(point endPoint);
void initFrame();
int inputKeyboard();
point moveSnake(int direction);
bool snakeEat(point food);
point initFood();
bool checkImpact();
void displayFood();


