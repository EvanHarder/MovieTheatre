#include <string>
#include <iostream>
#include <fstream>
#include "movie.h"
#include "theatre.h"
//default constructor
    Movie::Movie()
    : title("UNTITLED"), duration(0), rating("NR"), startTime("00:00") {}
//constructor
    Movie::Movie(std::string title, int duration, std::string rating, std::string startTime) : title(title),duration(duration),rating(rating),startTime(startTime) {}
//getters
    std::string Movie::getTitle() const {
        return this->title;
    };
    int Movie::getDuration() const {
        return this->duration;
    };
    std::string Movie::getRating() const {
        return this->rating;
    };

    std::string Movie::getStartTime() const {
        return this->startTime;
    };

//setters
    std::string Movie::setTitle(std::string title){
        return this->title = title;
    };
    int Movie::setDuration(int duration){
        return this->duration = duration;
    };
    std::string Movie::setRating(std::string rating){
        return this->rating = rating;
    };

    std::string Movie::setStartTime(std::string startTime){
        return this->startTime = startTime;
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

    //TODO: turn duration into an int
    std::cout << "Rating of Movie" << std::endl;
    std::cin >> r;

    //making file
    //replace test.txt with inputted name;
    std::ofstream file("./listOfMovies/test.txt");
    if (!file.is_open()) {
        std::cout << "Error Creating Movie!" << std::endl;
    }

    //putting inputs into a file
    file << t << std::endl;
    file << d << std::endl;
    file << r << std::endl;
    //TODO: maybe put what theatre number for clarity?
    std::cout << "Movie Created" << std::endl;
    file.close();
    }

    //create a theatre object, create a movie object. put the movie object into the theatre, update theatre file, delete objects afterword (happens naturally)
    void assignMovie(){
        int theatreNumber = 1;

        Movie tempMovie;
        Theatre tempTheatre(1,1);

        //reads all theates and movies, assigns a movie to that theatre.
        //changes the temp theatre into a theatre in file, theatreNumber is to grab the exact one expecting a int input after reading;
        theatreUtil::loadTheatre(tempTheatre,std::string("theatre") + std::to_string(theatreNumber) + ".txt");
        tempTheatre.setMovie(tempMovie);
        theatreUtil::unloadTheatre(tempTheatre);
    };

//     void readMovies(){
//     int amount = 1;
//     //format
//     std::cout << "----------------List of Movies----------------" << std::endl;
//     //open dir and error check
//     DIR* dir = opendir("./listOfMovies");
//     if (dir == NULL){
//         std::cout << "Error opening directory" << std::endl;
//     }

//     //read
//     struct dirent* entry;
//     while ((entry = readdir(dir)) != NULL) {
//         std::string file = entry->d_name;
//         if(!(file == "." || file == "..")){
//         amount++;
//         }

//     }

//     closedir(dir);
// }


}//end iof class
