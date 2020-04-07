#include <iostream>
#include "menuGame.h"
#include "gamePlay.h"
using namespace std;

int main(){
    int option;
    int level;
    initGame();
    cout<<"Please enter your choice: ";
    cin>>option;
    if (option==1) {
        system("cls");
        initSnake();
    }
    else if (option==2) {
        cout<<"Enter level you want (easy,medium,advance): ";
        cin>>level;
    }
    else return 0;
    return 0;
}