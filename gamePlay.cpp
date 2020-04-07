#include "gamePlay.h"
using namespace std;
#define pointSnake 254 

void gotoXY(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void initSnake(){
    int x=0, y=0;
    while (1){
        system("cls");
        gotoXY(x,y);
        cout<< (char)pointSnake;
        Sleep(1000);
        x++;
    }
}