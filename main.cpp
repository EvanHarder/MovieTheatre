//TODO: Reset the theatre once the movie ends;
#include <iostream>
#include <string>
#include "movie.h"
#include "Theatre.h"
#include "formats.h"

//#incl
int main(){
    //input for menu
    std::string creation;
    int choice = 1;
    
    
    //Constant Variables
    const int AVAILABLECHOICES = 7;

    while (choice > 0 && choice < AVAILABLECHOICES){
        //format (spacing)
        clearScreen();

        //grab choice in menu
        choice = menu();

        //booking a seat and reciept (just a confirmation that they got the seats they selected. doesnt need to be an object for this scale)
        if (choice == 1){
            booking();
        }

        //creating theatre
        else if(choice == 2){
            theatreUtil::readTheatres();
            std::cout << "Do you want to create a theatre? (Y/N): " << std::endl;
            std::cin >> creation;
            creation = convertUpper(creation);
            if (creation=="Y"||creation=="YES"){
                Theatre::createTheatre();
            }
        }

        //remove theates
        else if(choice == 3){
            Theatre::removeTheatre();
        }
        //create a movie
        else if (choice == 4){
            movieUtil::createMovie();
        }
        //remove a movie
        else if(choice == 5){
            movieUtil::removeMovie();
        }
        //assign a movie to a theatre
        else if (choice == 6){
            movieUtil::assignMovie();
        }
    }
}//main