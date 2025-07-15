#pragma once
#include <string>
class Movie {
    public:
    //default constructor
    Movie();
    //constructor
    Movie(std::string title, int duration, std::string rating, std::string startTime);
    //getters
    std::string getTitle() const;
    int getDuration() const;
    std::string getRating() const;
    std::string getStartTime() const;

    //setters
    std::string setTitle(std::string title);
    int setDuration(int duration);
    std::string setRating(std::string rating);
    std::string setStartTime(std::string startTime);



    //variables
    private:
        std::string title;
        int duration;
        std::string rating;
        std::string startTime;
};
//todo
namespace movieUtil{
    //checks startTime and duration to see if the movie is done playing
    bool movieFinished(Movie &movie);
    void createMovie();
    void assignMovie();
    void readMovies();
}