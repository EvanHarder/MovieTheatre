//TODO make the theatre classes have a movie attached. Seat avaiabliltiy. be able to create multiple theatre files.
#include <iostream>
#include <string>
//headers
#include "Theatre.h"
#include "app.h"
#include "formats.h"
int main(){
    //base theatre  
    Theatre theatre(1,1);
    std::string creation;
    int choice = 1;
    //probably can fix the hardcode
    while (choice>0&&choice<4){
        //format
        clearScreen();
        //grab choice
        choice = menu();


        //booking a seat
        if (choice == 1){
            //TODO: ask for a theatre, movie name and seats available;
            //TODO: reciept (just a cohfimration that they got the seats they collecgted. doesnt need to be an object for this scale)
            Theatre::readTheatres();
            theatreUtil::loadTheatre(theatre);
            app(theatre);
            theatreUtil::unloadTheatre(theatre);
        }

        //creating theatre
        else if(choice == 2){
            Theatre::readTheatres();
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
            Theatre::readTheatres();
            Theatre::removeTheatre();
        }
    }
}//main