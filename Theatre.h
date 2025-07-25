#pragma once
#include <vector>
#include "movie.h"

class Theatre{
public:
//constructor
    Theatre(int rows, int columns);
//getters
    int getRows();
    int getColumns();
    std::vector<std::vector<bool>> getSeats();
    std::string getName();
    Movie& getMovie();
//setters
    void selectSeat(int row,int column);
    void setName(std::string name);
    void setSeats(int rows, int columns,int value);
    void setRows(int rows);
    void setColumns(int columns);
    void setMovie(Movie& movie);
//resize seating and resetting
    void fixSeating();
    void resetSeating();
//unbooked seats
int showAvailableSeats();
//printing bugtest
    void showTheatreValues();
//file manipulation
    void static removeTheatre();
    void static createTheatre();
//time
    void movieFinished();
private:
    std::string name;
    int rows;
    int columns;
    std::vector<std::vector<bool>> seats;
    Movie movie;




};
namespace theatreUtil{

    //theatre read and write
    void unloadTheatre(Theatre &theatre, std::string fileName);
    void loadTheatre(Theatre &theatre, std::string fileName);
    //reads theatres from directory
    void readTheatres();
    //when creating a theatre what number to put in file
    int getTheatreNumber();
    int amountOfTheatres();
    //processes input for theatre selection
    int intEnteredTheatre();
}
