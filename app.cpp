#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "app.h"
//TODO: Perfect unless bugs!
//compiling
//g++ app.cpp -o app -lsfml-graphics -lsfml-window -lsfml-system

//this takes an array from a file. shows the file. then if clicked and booked a seat it returns an array
void app(Theatre& theatre) {
    //vector of squares
    std::vector<sf::RectangleShape> squares;
    //grabbing seats from Theatre
    std::vector<std::vector<bool>> seats = theatre.getSeats();

    //LIMITS: 14 columns 13 rows
    int rows = theatre.getRows();
    int columns = theatre.getColumns();

    //square dimensions
    int squareSize = 30;

    //number to make sure the squares fit into the window and for borders, spacing is pixels between the squares
    int spacing = 10;

    //window dimensions
    int xAxis;
    int yAxis;
    if (rows > 13 || columns > 14){
        xAxis = 600+((squareSize+spacing)*(columns-14));
        yAxis = 600+((squareSize+spacing)*(rows-13));
    }
    else{
        xAxis = 600;
        yAxis = 600;
    }

    //spacing dimensions
  
    int xAxisCenter = xAxis - 80;
    int yAxisCenter = yAxis - 120;
    int startX = (xAxis - xAxisCenter) / 2;
    int startY = (yAxis - yAxisCenter) / 2;
    //changing x spots when incrementing squares

    float xspot;
    float yspot;
    //boolean for confirm
    bool confirmChoice = false;
    
    //window and confirm square
    sf::RenderWindow window(sf::VideoMode(xAxis, yAxis), theatre.getName());
    sf::RectangleShape confirm(sf::Vector2f(squareSize, squareSize));
    confirm.setPosition(0,0);
    confirm.setFillColor(sf::Color::Green);

    //creating clickable seats and putting into a vector
    for(int x = 0; x< rows; x++){
        for(int j = 0; j < columns; j++){
            sf::RectangleShape newSquare(sf::Vector2f(squareSize, squareSize));
            xspot = startX + j * (squareSize + spacing);
            yspot = startY + x * (squareSize + spacing);
            newSquare.setPosition(xspot,yspot);
            if (seats[x][j]==true){
                newSquare.setFillColor(sf::Color::Red);
            }
            else{
                newSquare.setFillColor(sf::Color::Cyan);
            }
            squares.push_back(newSquare);
        }
}


    //Creating screen square
    sf::RectangleShape Screen(sf::Vector2f((xspot-startX),15));
    Screen.setPosition(startX+(squareSize/2),startY/columns);
    Screen.setFillColor(sf::Color::White);

    //while making app interactable
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();
            }



            // reacts when you click on a square
            if (event.type == sf::Event::MouseButtonPressed) {
                //getting mouseposition
                auto mousePos = sf::Mouse::getPosition(window);

                //increasing a counter to check which square you clicked
                int counter = 0;
                //go through every square
                for (auto& square : squares) {

                    //if clicked on a square say what square and then switch its color
                    if (square.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        //incase of bug fixing
                        //std::cout << "Square " << counter+1 <<  " clicked!" << std::endl;

                        //confirm & unconfirm squares
                        if (square.getFillColor() == sf::Color::Yellow){
                            square.setFillColor(sf::Color::Cyan);
                        if(counter%columns==0){
                            theatre.selectSeat(counter/columns,columns);
                        }
                            theatre.selectSeat(counter/columns,(counter%columns));
                        }
                        else if(square.getFillColor() == sf::Color::Red){
                            break;
                        }
                        else{
                          //debuging code: std::cout << "Rows" << counter/columns << "COLUMNS: " << counter%columns << std::endl;
                          square.setFillColor(sf::Color::Yellow);
                          if(counter%columns==0){
                              theatre.selectSeat(counter/columns,columns);
                          }
                             theatre.selectSeat(counter/columns,(counter%columns));
                        }
                    }

                    counter++;
              }
                //confirming choice
                if (confirm.getGlobalBounds().contains(mousePos.x, mousePos.y)){
                //maybe for debugging?
                //std::cout << "confirm clicked" << std::endl;
                  window.close();
                }
            }
            
        }

        //constant frames/drawing
        //backwork drawing squares and opening the window 
        window.clear();
        for (const auto& square : squares) {
            window.draw(square);

            //if a seat is chosen show confirm square
            if(square.getFillColor()==sf::Color::Yellow){
            confirmChoice = true;    
            }
        }
            //if a seat is chosen show confirm square
            if (confirmChoice){
            window.draw(confirm);
            }
            //if seats are unpicked get rid of the confirm square
            confirmChoice = false;
            window.draw(Screen);
            window.display();
    }
}