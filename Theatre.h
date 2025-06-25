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
//printing bugtest
    void showTheatreValues();
private:
    std::string name;
    int rows;
    int columns;
    std::vector<std::vector<bool>> seats;




};