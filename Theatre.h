#pragma once
#include <vector>

class Theatre{
public:
//constructor
    Theatre(int rows, int columns);
//getters
    int getRows();
    int getColumns();
    std::vector<std::vector<bool>> getSeats();
    std::string getName();
//setters
    void selectSeat(int row,int column);
    void setName(std::string name);
    void setSeats(int rows, int columns,int value);
    void setRows(int rows);
    void setColumns(int columns);
//resize seating
    void fixSeating();
//unbooked seats
int showAvailableSeats();
//printing bugtest
    void showTheatreValues();
//file manipulation
    void static removeTheatre();
    void static createTheatre();
private:
    std::string name;
    int rows;
    int columns;
    std::vector<std::vector<bool>> seats;
    //not a pointer because only one movie object will be created
    //Movie movie;




};
namespace theatreUtil{
    void unloadTheatre(Theatre &theatre);
    void loadTheatre(Theatre &theatre, std::string fileName);
    void readTheatres();
}
