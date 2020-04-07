#include "menuGame.h"
using namespace std;

void initGame(){
    string name;
    cout<<setw(50)<<"NVT Game"<<endl;
    cout<<setw(56)<<"Please enter your name: ";
    cin>>name;
    cout<<setw(38)<<"Hello "<<name<<"! Welcome to my game"<<endl;
    cout<<"****************************************Menu Game***************************************************"<<endl;
    cout<<setw(49)<<"New Game"<<endl;
    cout<<setw(47)<<"Level"<<endl;
    cout<<setw(47)<<"Exit"<<endl;
    cout<<"****************************************************************************************************"<<endl;
}