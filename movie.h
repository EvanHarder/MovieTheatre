#pragma once
#include <string>
class Movie {
    public:
    //default constructor
    Movie();
    //constructor
    Movie(std::string title, std::string duration, std::string rating, std::string startTime, int day);
    //getters
    std::string getTitle() const;
    std::string getDuration() const;
    std::string getRating() const;
    std::string getStartTime() const;
    int getDay() const;

    //setters
    void setTitle(std::string title);
    void setDuration(std::string duration);
    void setRating(std::string rating);
    void setStartTime(std::string startTime);
    void setDay(int day);

    //variables
    private:
        std::string title;
        std::string duration;
        std::string rating;
        std::string startTime;
        int day;
};
//todo
namespace movieUtil{
    //creates a file for a movie
    void createMovie();
    //removes a file for a movie
    void removeMovie();
    //returns a movie upon recieving the fileName. its a Movie funciton because this program doesnt always need to have a movie object. false if not in a theatreobjecft true if it is
    Movie loadMovie(std::string fileName, bool inTheatreObject);
    void assignMovie();
    void readMovies();
    //when creating a theatre what number to put in file
    int getMovieNumber();
    int amountOfMovies();
    //processes input for movie selection
    int intEnteredMovie();
    //processes input for movie
    std::string ratingValid();
    //process duration input
    std::string durationValid();
}