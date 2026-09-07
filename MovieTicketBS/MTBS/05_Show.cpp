#ifndef SHOW_CPP
#define SHOW_CPP

#include <string>
#include <vector>
#include "01_Movie.cpp"
#include "03_Screen.cpp"
#include "06_ShowSeat.cpp"
using namespace std;

class Show{
private:
    Movie *movie;
    Screen *screen;
    string start_time;
    vector<ShowSeat> showSeats;
    
public:
    Show(Movie *movie,Screen *screen,string start_time){
        this->movie = movie;
        this->screen = screen;
        this->start_time = start_time;
        
        for(auto s: screen->getSeats()){
            showSeats.push_back(ShowSeat(s.getSeatNumber(),s.getSeatType()));
        }
    }


Movie *getMovie(){return movie;}
Screen *getScreen(){return screen;}
string getStartTime(){return start_time;}

vector<ShowSeat> &getShowSeats(){return showSeats;}

ShowSeat* getSeat(string seatNumber){
    for(int i = 0; i < showSeats.size();i++){
        if(showSeats[i].getSeatNumber() == seatNumber)return &showSeats[i];
    }
    return nullptr;
}
};

#endif
