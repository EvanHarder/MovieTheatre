#include <string>
#include <iostream>
#include <fstream>
#include <dirent.h>
#include "movie.h"
#include "theatre.h"
//default constructor
    Movie::Movie()
    : title("UNTITLED"), duration("0:00"), rating("NR"), startTime("00:00") {}
//constructor
    Movie::Movie(std::string title, std::string duration, std::string rating, std::string startTime) : title(title),duration(duration),rating(rating),startTime(startTime) {}
//getters
    std::string Movie::getTitle() const {
        return this->title;
    };
    std::string Movie::getDuration() const {
        return this->duration;
    };
    std::string Movie::getRating() const {
        return this->rating;
    };

    std::string Movie::getStartTime() const {
        return this->startTime;
    };

//setters
    void Movie::setTitle(std::string title){
        this->title = title;
    };
    void Movie::setDuration(std::string duration){
        this->duration = duration;
    };
    void Movie::setRating(std::string rating){
        this->rating = rating;
    };

    void Movie::setStartTime(std::string startTime){
        this->startTime = startTime;
    };


namespace movieUtil{
    //checks startTime and duration to see if the movie is done playing
    //bool movieFinished(Movie &movie);

    void createMovie(){

    std::string t,r,d;
    //inputs
    std::cout << "Title of Movie:" << std::endl;
    std::cin >> t;
    std::cout << "Duration of Movie" << std::endl;
    std::cin >> d;
    std::cout << "Rating of Movie" << std::endl;
    std::cin >> r;

    //making file
    //replace test.txt with inputted name;
    std::ofstream file("./listOfMovies/" + (std::string("movie") + std::to_string(movieUtil::getMovieNumber()) + ".txt"));
    if (!file.is_open()) {
        std::cout << "Error Creating Movie!" << std::endl;
    }

    //putting inputs into a file
    file << t << std::endl;
    file << d << std::endl;
    file << r << std::endl;
    //TODO: maybe put what movie number for clarity?
    std::cout << "Movie " << movieUtil::getMovieNumber()-1 << " Created" << std::endl;
    file.close();
    }

    //removes a movie
    void removeMovie(){
        int movieSelected;
        movieUtil::readMovies();
        std::cout << "What movie do you want to delete: " << std::endl;
        std::cin >> movieSelected;
        if(remove(("./listOfMovies/" + (std::string("movie") + std::to_string(movieSelected) + ".txt")).c_str()) == 0){
            std::cout << "Removed Movie" << std::endl;
        }
        else{
            std::cout << "Error removing Movie" << std:: endl;;
        }
    }


    //create a theatre object, create a movie object. put the movie object into the theatre, update theatre file, delete objects afterword (happens naturally)
    void assignMovie(){
        int theatreNumber = 3;
        int movieNumber = 1;

        Movie tempMovie;
        Theatre tempTheatre(1,1);

        //select & load movie
        movieUtil::readMovies();
        std::cout << "What movie to assign: ";
        std::cin >> movieNumber;
        tempMovie = movieUtil::loadMovie(std::string("movie") + std::to_string(movieNumber) + ".txt",false);

        //select & load theatre
        theatreUtil::readTheatres();
        std::cout << "To theatre: ";
        std::cin >> theatreNumber;
        theatreUtil::loadTheatre(tempTheatre,std::string("theatre") + std::to_string(theatreNumber) + ".txt");

        //place movie into theatre
        tempTheatre.setMovie(tempMovie);
        theatreUtil::unloadTheatre(tempTheatre,std::string("theatre") + std::to_string(theatreNumber) + ".txt");
    };

//set a bool
    Movie loadMovie(std::string fileName, bool inTheatreObject = false){
    Movie tempMovie;
    std::string line;
    std::ifstream file;

    if(!inTheatreObject){

    file.open("./listOfMovies/" + fileName);
    if (!file.is_open()) {
        std::cout << "Error opening Movie!" << std::endl;
        return tempMovie;
    }

    }
    else{
        file.open("./listOfTheatres/" + fileName);
        if (!file.is_open()) {
            std::cout << "Error opening Theatre!" << std::endl;
            return tempMovie;
        }
        std::getline(file,line);
        std::getline(file,line);
        std::getline(file,line);
    }
    //setting movie parameters, title,duration,rating,starttime
    
    std::getline(file,line);
    tempMovie.setTitle(line);
    std::getline(file,line);
    tempMovie.setDuration(line);
    std::getline(file,line);
    tempMovie.setRating(line);
    return tempMovie;
    }


    void readMovies(){
    int amount = 1;
    Movie temp;
    //format
    std::cout << "----------------List of Movies----------------" << std::endl;
    //open dir and error check
    DIR* dir = opendir("./listOfMovies");
    if (dir == NULL){
        std::cout << "Error opening directory" << std::endl;
    }

    //read
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        std::string file = entry->d_name;
        if(!(file == "." || file == "..")){
            temp = movieUtil::loadMovie(file,false);
            std::cout << "========================" << std::endl;
            std::cout << "      Movie " << amount << ": "  << std::endl;
            std::cout << "Title: " << temp.getTitle() << std::endl;
            std::cout << "Duration: " << temp.getDuration() << std::endl;
            std::cout << "Rating: " << temp.getRating() << std::endl;
            std::cout << "========================" << std::endl;
            amount++;
        }

    }

    closedir(dir);
}

int getMovieNumber(){
    int amount = 1;

    //open dir and error check
    DIR* dir = opendir("./listOfMovies");
    if (dir == NULL){
        std::cout << "Error opening directory" << std::endl;
    }

    //read
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        std::string file = entry->d_name;
        if(!(file == "." || file == "..")&& file.size() > 4 && file.substr(file.size()-4) == ".txt"){
            if(!(file == std::string("movie") + std::to_string(amount) + ".txt")){
                closedir(dir);
                return amount;
            }
        amount++;
        }

    }
    closedir(dir);
    return amount++;
}

}//end of namespace
