#ifndef CINEMA_CPP
#define CINEMA_CPP

#include <string>
#include <vector>
#include "03_Screen.cpp"
using namespace std;

class Cinema{
private:
    string name;
    vector<Screen> screens;
    
public:
    Cinema(string name){
        this->name = name;
        screens.push_back(Screen(1));
        screens.push_back(Screen(2));
    }
    
    string getName(){return name;}
    vector<Screen> &getScreens(){return screens;}
};


#endif
