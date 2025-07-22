#include "formats.h"
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
std::string durationValid(){
    std::string choice;
    bool passed = false;
    while(!passed){
        std::cin >> choice;

    //check if int
        if (choice.length() != 4 || !isdigit(choice[0]) || !isdigit(choice[2]) ||  !isdigit(choice[3])) {
            std::cout << "Invalid string. Please enter with a format of 0:00 .\n";
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
