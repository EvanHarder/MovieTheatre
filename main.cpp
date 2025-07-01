#include <iostream>
#include "Theatre.h"
#include "app.h"
#include <string>

int main(){
    //base theatre
    Theatre theatre(1,1);



    std::string creation;
    std::cout << "Do you want to create a theatre? (Y/N): " << std::endl;
    std::cin >> creation;

    if (creation=="Y"||creation=="y"||creation=="yes"){
         Theatre::createTheatre();
    }
    theatreUtil::loadTheatre(theatre);
    app(theatre);
    theatreUtil::unloadTheatre(theatre);
    Theatre::readTheatres();
    //Theatre::removeTheatre();
}