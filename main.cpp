//TODO be able to create multiple theatre files. Reset the theatre once the movie ends;
#include <iostream>
#include <string>
//headers
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
    int theatreSelected;
    
    //Constant Variables
    const int AVAILABLECHOICES = 4;

    while (choice > 0 && choice <= AVAILABLECHOICES){
        //format
        clearScreen();
        //grab choice
        choice = menu();

        //booking a seat
        if (choice == 1){
            //TODO: ask for a theatre, movie name and seats available;
            //TODO: reciept (just a cohfimration that they got the seats they collecgted. doesnt need to be an object for this scale)
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
            //ask for a theatre Name;
            theatreUtil::readTheatres();
            Theatre::removeTheatre();
        }

        else if (choice == 4){
            //error here make sure to fix how the theatres are called.
            movieUtil::assignMovie();
        }
    }
}//main