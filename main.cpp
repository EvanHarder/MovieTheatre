//TODO: Reset the theatre once the movie ends;
#include <iostream>
#include <string>
#include "movie.h"
#include "Theatre.h"
#include "app.h"
#include "formats.h"

//#incl
int main(){
    //base theatre  
    Theatre theatre(1,1);

    //input for menu
    std::string creation;
    int choice = 1;

    
    //Constant Variables
    const int AVAILABLECHOICES = 7;

    while (choice > 0 && choice < AVAILABLECHOICES){
        //format
        clearScreen();

        //grab choice
        choice = menu();

        //booking a seat
        if (choice == 1){
            //TODO: ask for a theatre, movie name and seats available;
            //TODO: reciept (just a cohfimration that they got the seats they collecgted. doesnt need to be an object for this scale)
            int theatreSelected;
            theatreUtil::readTheatres();
            std::cout << "What theatre do you want to book for?: " << std::endl;
            std::cin >> theatreSelected;

            theatreUtil::loadTheatre(theatre,std::string("theatre") + std::to_string(theatreSelected) + ".txt");

            app(theatre);
            theatreUtil::unloadTheatre(theatre,std::string("theatre") + std::to_string(theatreSelected) + ".txt");
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

        else if (choice == 4){
            //error here make sure to fix how the theatres are called.
            movieUtil::createMovie();
        }
        else if(choice == 5){
            //remove movie
            movieUtil::removeMovie();
        }
        else if (choice == 6){
            //assign movie
            movieUtil::assignMovie();
        }
    }
}//main