#include "formats.h"
#include <string>
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