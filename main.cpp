#include <iostream>
#include "menuGame.h"
#include "gamePlay.h"
using namespace std;

int main(){
    int option;
    int level;
    int direction=DOWN;
    int gameScore=0;
    point endPoint;
    int speedLevel=500;
    bool check=true;
    string name;
    highScore hs;
    cout<<setw(50)<<"NVT Game"<<endl;
    initGame();
    while (check){
        cout<<"Please enter your choice: ";
        cin>>option;    
        if (option==1) {
            cout<<setw(56)<<"Please enter your name: ";
            cin>>name;
            system("cls");
            initFrame();
            initSnake();
            point food;
            food = initFood();
            while(1){
                if (snakeEat(food)){food=initFood(); gameScore++;}
                if (checkImpact()){
                    system("cls"); 
                    cout<<"GAME OVER! Your score: "<<gameScore<<endl; 
                    hs.addHighScore(name, gameScore);
                    gameScore=0;
                    direction=DOWN;
                    displayMenu(); 
                    break;
                }
                endPoint=moveSnake(direction);
                displaySnake(endPoint);
                if(kbhit()){
                    direction=inputKeyboard();
                }
                Sleep(speedLevel);
            }    
        }
        else if (option==2) {
            system("cls");
            cout<<"1.Easy"<<endl;
            cout<<"2.Medium"<<endl;
            cout<<"3.Advance"<<endl;
            cout<<"Enter level you want (1,2,3): ";
            cin>>level;
            if (level==1) {speedLevel=1000; cout<<"You chose Easy Level!";}
            else if (level==2) {speedLevel=500; cout <<"You chose Medium Level";}
            else {speedLevel=100; cout<<"You chose Advance Level";}
            Sleep(1000);
            system("cls");
            displayMenu();
        }
        else if (option==3){
            hs.displayHighScore();
            while (1){
                if (kbhit()){
                    char ESCPress=getch();
                    int asciiValue=ESCPress;
                    if (asciiValue==27){
                        system("cls");
                        displayMenu();
                        break;
                    }
                }
            }
        }
        else break;
    }
    return 0;
}