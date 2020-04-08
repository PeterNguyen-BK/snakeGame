#include <iostream>
#include "menuGame.h"
#include "gamePlay.h"
using namespace std;

int main(){
    int option;
    int level;
    int direction=DOWN;
    point endPoint;
    initGame();
    cout<<"Please enter your choice: ";
    cin>>option;
    if (option==1) {
        system("cls");
        initSnake();
        initFrame();
        initFood();
        while (1){
            if (snakeEat()){
                initFood();
            }
            endPoint=moveSnake(direction);
            if(kbhit()){
                direction=inputKeyboard();
            }
            displaySnake(endPoint);
            if (!checkImpact()){system("cls"); cout<<"GAME OVER"; break;}
            Sleep(200);
        }    
    }
    else if (option==2) {
        cout<<"Enter level you want (easy,medium,advance): ";
        cin>>level;
    }
    else return 0;
    return 0;
}