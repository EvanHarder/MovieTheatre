#pragma once
#include <string>
class Movie {
    public:
    //default constructor
    Movie();
    //constructor
    Movie(std::string title, std::string duration, std::string rating, std::string startTime);
    //getters
    std::string getTitle() const;
    std::string getDuration() const;
    std::string getRating() const;
    std::string getStartTime() const;

    //setters
    void setTitle(std::string title);
    void setDuration(std::string duration);
    void setRating(std::string rating);
    void setStartTime(std::string startTime);

    //variables
    private:
        std::string title;
        std::string duration;
        std::string rating;
        std::string startTime;
};
//todo
namespace movieUtil{
    //checks startTime and duration to see if the movie is done playing
    //bool movieFinished(Movie &movie);
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
}