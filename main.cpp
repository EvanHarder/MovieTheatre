#include <iostream>
#include "Theatre.h"
#include "app.h"
#include <fstream>
#include <vector>
#include <string>
//functions
void loadTheatre();
void unloadTheatre(Theatre theatre);
void createTheatre();

//global variables
Theatre theatre(1,1);

int main(){
    std::string creation;
    std::cout << "Do you want to create a theatre? (Y/YES): " << std::endl;
    std::cin >> creation;

    if (creation=="y"||creation=="Yes"){
        createTheatre();
    }
    loadTheatre();
    app(theatre);
    unloadTheatre(theatre);

}

//TODO: write and read files
void createTheatre(){

    int r,c;
    //inputs
    std::cout << "How many rows?" << std::endl;
    std::cin >> r;
    std::cout << "How many columns?" << std::endl;
    std::cin >> c;

    //making file
    std::ofstream file("test.txt");
    if (!file.is_open()) {
        std::cout << "Error opening file!" << std::endl;
    }

    //putting inputs into a file
    file << r << std::endl;
    file << c << std::endl;
        for(int x = 0; x< r; x++){
        for(int j = 0; j < c; j++){
            file << 0 << " ";
        }
    }

    
    file.close();
};




void loadTheatre(){
    std::ifstream file("test.txt");
    int number;
    if (!file.is_open()) {
        std::cout << "Error opening file!" << std::endl;
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
    file.close();
};


void unloadTheatre(Theatre theatre){
    std::vector<std::vector<bool>> seats = theatre.getSeats();
        std::ofstream file("test.txt");
    if (!file.is_open()) {
        std::cout << "Error opening file!" << std::endl;
    }
    file << theatre.getRows() << std::endl;
    file << theatre.getColumns() << std::endl;
        for(int x = 0; x< theatre.getRows(); x++){
        for(int j = 0; j < theatre.getColumns(); j++){
            file << seats[x][j] << " ";
        }
    }

    
    file.close();
};
