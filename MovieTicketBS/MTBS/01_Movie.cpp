
#ifndef MOVIE_CPP
#define MOVIE_CPP

#include <string>
using namespace std;

class Movie{
private:
    string title;
    string lang;
    int duration_movie;
    
public:
    Movie(string title,string lang,int duration_movie){
        this->title = title;
        this->lang = lang;
        this->duration_movie = duration_movie;
    }
    
    int getDuration(){
        return duration_movie;
    }
    
    string getTitle(){
        return title;
    }
    
    string getLanguage(){
        return lang;
    }
};

#endif
