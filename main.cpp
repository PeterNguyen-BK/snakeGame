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
        initFrame();
        initSnake();
        point food;
        food = initFood();
        while(1){
            if (snakeEat(food)){food=initFood();}
            if (checkImpact()){system("cls"); cout<<"GAME OVER!"; break;}
            endPoint=moveSnake(direction);
            displaySnake(endPoint);
            if(kbhit()){
                direction=inputKeyboard();
            }
            Sleep(300);
        }    
    }
    else if (option==2) {
        cout<<"Enter level you want (easy,medium,advance): ";
        cin>>level;
    }
    else return 0;
    return 0;
}