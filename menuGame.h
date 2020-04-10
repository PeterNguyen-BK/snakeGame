#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <vector>
using namespace std;

class highScore{
    vector<string> name;
    vector<int> score;
    public:
    void addHighScore(string _name, int _score ){
        this->name.push_back(_name);
        this->score.push_back(_score);
    }
    void displayHighScore(){
        for (int i=0;i<this->name.size();i++){
            cout<<this->name[i]<<setw(5)<<this->score[i]<<endl;
        }
    }
};

void initGame();
void displayMenu();
