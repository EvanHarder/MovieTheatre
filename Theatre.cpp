#include <iostream>
#include <fstream>
#include <string>
#include "Theatre.h"
#include <vector>
#include <dirent.h>

    //constructor
    Theatre::Theatre(int rows, int columns)
        : name("UNTITLED THEATRE"),rows(rows),columns(columns),seats(rows, std::vector<bool>(columns)), movie() {}

    //Getters
    std::vector<std::vector<bool>> Theatre::getSeats(){return seats;}
    
    int Theatre::getRows(){return rows;}
    
    int Theatre::getColumns(){return columns;}

    Movie& Theatre::getMovie(){return movie;}
    
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

    void Theatre::setMovie(Movie& movie){
        this->movie=movie;
    }
    
    //change theatre name for when the movie changes... should probably add time for when the movie is occuring.. maybe movie is an object with its own time and name and then the theatres have availabliklty?
    void Theatre::setName(std::string name){this->name = name;}

    //show values (bug testing)
    void Theatre::showTheatreValues(){
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


    //how many seats not booked in a theatre
    int Theatre::showAvailableSeats(){
        int temp = 0;
                for(int x = 0; x< rows; x++){
            for(int j = 0; j < columns; j++){
                if (seats[x][j]==false){
                    temp++;
                }
            }
        }
        return temp;
    }

void Theatre::resetSeating(){
    for(int x = 0; x< rows; x++){
        for(int j = 0; j < columns; j++){
            seats[x][j] = 0;
        }
    }
}

//file manipulation

void Theatre::removeTheatre(){
    if(remove("listOfTheatres/test.txt") == 0){
        std::cout << "Removed Theatre" << std::endl;
    }
    else{
        std::cout << "Error removing Theatre" << std:: endl;;
    }
}

//integrate into theatreclass Theatre::createTheatre;
void Theatre::createTheatre(){

    int r,c;
    //inputs
    std::cout << "How many rows?" << std::endl;
    std::cin >> r;
    std::cout << "How many columns?" << std::endl;
    std::cin >> c;
    Theatre tempTheatre(1,1);
    //putting inputs into a file
    tempTheatre.setRows(r); 
    tempTheatre.setColumns(c);
    //resizes the global theatre using the new variables;
    tempTheatre.fixSeating();
    theatreUtil::unloadTheatre(tempTheatre,"newTheatre.txt");

    //TODO: maybe put what theatre number for clarity?
    std::cout << "Theatre Created" << std::endl;;
}



namespace theatreUtil{

void unloadTheatre(Theatre &theatre, std::string fileName){
    std::vector<std::vector<bool>> seats = theatre.getSeats();
        std::ofstream file("./listOfTheatres/" + fileName);
    if (!file.is_open()) {
        std::cout << "Error opening Theatre!" << std::endl;
    }
    file << theatre.getRows() << std::endl;
    file << theatre.getColumns() << std::endl;
        for(int x = 0; x< theatre.getRows(); x++){
        for(int j = 0; j < theatre.getColumns(); j++){
            file << seats[x][j] << " ";
        }
    }
    //string issues sizing
    file << std::endl << theatre.getMovie().getTitle() << std::endl;
    file << theatre.getMovie().getDuration() << std::endl;
    file << theatre.getMovie().getRating() << std::endl;
    file << theatre.getMovie().getStartTime() << std::endl;

    
    file.close();
}


    void loadTheatre(Theatre &theatre, std::string fileName){
    std::ifstream file("./listOfTheatres/" + fileName);
    int number;
    if (!file.is_open()) {
        std::cout << "Error opening Theatre!" << std::endl;
        return;
    }

    //grabs rows and columns
    std::string line;
    std::getline(file,line);
    theatre.setRows(std::stoi(line)); 
    std::getline(file,line);
    theatre.setColumns(std::stoi(line));
    //resizes the global theatre using the new variables;
    theatre.fixSeating();

    //goes through every number and changes the seating to the true false
    for(int x = 0; x< theatre.getRows(); x++){
        for(int j = 0; j < theatre.getColumns(); j++){
            file >> number;
            theatre.setSeats(x,j,number);
        }
    }
    std::getline(file,line); //getline to clear the rest of the seating array numbers
    //file read movie
    Movie tempMovie = movieUtil::loadMovie(fileName,true);

    theatre.setMovie(tempMovie);
    file.close();
}


void readTheatres(){
    int amount = 1;
    Theatre temp(1,1);
    //format
    std::cout << "----------------List of Theaters----------------" << std::endl;
    //open dir and error check
    DIR* dir = opendir("./listOfTheatres");
    if (dir == NULL){
        std::cout << "Error opening directory" << std::endl;
    }

    //read
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        std::string file = entry->d_name;
        if(!(file == "." || file == "..")){
        theatreUtil::loadTheatre(temp,file);
        std::cout << "========================" << std::endl;
        std::cout << "      THEATRE " << amount << ": " << std::endl << "TITLE: " << temp.getMovie().getTitle() << std::endl <<"START TIME: " << temp.getMovie().getStartTime() << std::endl << "DURATION: " << temp.getMovie().getDuration() << std::endl << "RATING: " << temp.getMovie().getRating() << std::endl << "AVAILABLE SEATS: " << temp.showAvailableSeats() << std::endl;
        std::cout << "========================" << std::endl;
        amount++;
        }

    }

    closedir(dir);
}


}