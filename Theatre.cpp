#include <iostream>
#include <string>
#include "Theatre.h"
//probably will need a new theater when CREATING a theatre
#include <vector>

    //constructor
    Theatre::Theatre(int rows, int columns)
        : name("UNTITLED THEATRE"),rows(rows),columns(columns),seats(rows, std::vector<bool>(columns)) {}

    //Getters
    std::vector<std::vector<bool>> Theatre::getSeats(){return seats;}
    
    int Theatre::getRows(){return rows;}
    
    int Theatre::getColumns(){return columns;}
    
    std::string Theatre::getName(){return name;}

    //Toggles if a seat is true
    void Theatre::selectSeat(int row,int column){
        if(seats[row][column]==false){
            seats[row][column]=true;
        }
        else{
            seats[row][column] = false;
        }
    }

    //remakes the seating grid
    void Theatre::fixSeating(){
        this->seats = std::vector<std::vector<bool>>(this->rows, std::vector<bool>(this->columns, false));
    }

    void Theatre::setSeats(int rows, int columns,int value){
        seats[rows][columns]=value;
    }
    void Theatre::setRows(int rows){
        this->rows=rows;
    }
    void Theatre::setColumns(int columns){
        this->columns=columns;
    }
    
    //change theatre name for when the movie changes... should probably add time for when the movie is occuring.. maybe movie is an object with its own time and name and then the theatres have availabliklty?
    void Theatre::setName(std::string name){this->name = name;}

    //show values (bug testing)
    void Theatre::showTheatreValues(){
        std::cout << name << std::endl;
        for(int x = 0; x< rows; x++){
            std::cout << "{";
            for(int j = 0; j < columns; j++){
                if (j == columns-1){
                    std::cout << seats[x][j];
                }
                else{
                std::cout << seats[x][j]<< ",";
                }
            }
        std::cout << "}" << std::endl;
        }
    }