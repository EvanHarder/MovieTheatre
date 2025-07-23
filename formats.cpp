#include "formats.h"
#include "app.h"
#include "Theatre.h"
#include <string>
#include <limits>
#include <iostream>
//converts string into capital string
std::string convertUpper(std::string creation){
    std::string upperCreation;
    for (size_t i = 0; i < creation.length(); i++){
        upperCreation += char(toupper(creation[i]));
    }
    return upperCreation;
}

//displays the menu
int menu(){
    int decision;
    std::cout << "What do you want to do?: " << std::endl;
    std::cout << "1) Book a seat" << std::endl;
    std::cout << "2) Create a new Theatre" << std::endl;
    std::cout << "3) Remove a Theatre" << std::endl;
    std::cout << "4) Create a Movie" << std::endl;
    std::cout << "5) Remove a Movie" << std::endl;
    std::cout << "6) Assign a Movie" << std::endl;
    std::cout << "7) Quit" << std::endl;
    std::cin >> decision;
    return decision;
}

//clearScreen
void clearScreen() {
    for (int i = 0; i < 10; ++i)
        std::cout << "\n";
}
int intValid(){
    int choice;
    bool passed = false;
    while(!passed){
        std::cin >> choice;

    //check if int
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a whole number.\n";
           std::cin.clear(); // Clear the error flags
           // Discard the rest of the invalid input line
           std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          passed = false; 
        } 
        else {
        passed = true;
        }
    }

    return choice;
}
void booking(){
    //base theatre  
    Theatre theatre(1,1);

    int firstAvailable;
    int secondAvailable;
    int seatsTaken;
    int theatreSelected;
    //input
    theatreUtil::readTheatres();
    std::cout << "What theatre do you want to book for?: " << std::endl;
    theatreSelected = theatreUtil::intEnteredTheatre();

    //load and unload
    theatreUtil::loadTheatre(theatre,std::string("theatre") + std::to_string(theatreSelected) + ".txt");
    firstAvailable = theatre.showAvailableSeats();
    app(theatre);
    secondAvailable = theatre.showAvailableSeats();
    theatreUtil::unloadTheatre(theatre,std::string("theatre") + std::to_string(theatreSelected) + ".txt");
    seatsTaken = firstAvailable - secondAvailable;
    //receipt
    std::cout << "=========== RECEIPT ===========" << std::endl;
    std::cout << "You've sucessfully selected " << seatsTaken << " seats" << std::endl;
    std::cout << "-------------------------------" << std::endl;
}
