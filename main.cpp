#include <iostream>
#include <SFML/Graphics.hpp>
#include "board.h"
#include "piece.h"
#include "pawn.hpp"
#include "human.hpp"

int main()
{

    Board *b = new Board();
    b->startGame();
    Human *h = new Human();
    sf::Vector2u targetSize(1000, 800);
    sf::RenderWindow w(sf::VideoMode(1000, 800), "Chess");
    w.setSize(targetSize);
    bool player1 = true;
    bool firstClick = true;
    bool moveMade = false;
    bool shouldDraw = false; 
    int xCord;
    int yCord;
    while (w.isOpen())
    {
        b->draw(w);
        sf::Event e;
        while (w.pollEvent(e))
        {
            if ((e.type == sf::Event::Closed))
            {
                w.close();
            }
            else if (e.type == sf::Event::MouseButtonPressed)
            {
                if (firstClick)
                {
                    if (e.mouseButton.button == sf::Mouse::Left)
                    {
                     sf::Vector2i mousePos = sf::Mouse::getPosition(w);
                        if(mousePos.x/100<=7 && mousePos.x/100 >=0 && mousePos.y/100>=0 && mousePos.y/100<=7)
                        {
                            if (h->select(mousePos.x, mousePos.y, b))
                            {
                                firstClick = false;
                                shouldDraw = true;
                                xCord = mousePos.x / 100;
                                yCord = mousePos.y / 100;
                               
                            }
                        }
                    }
                }
                else if (!firstClick)
                {
                    if (e.mouseButton.button == sf::Mouse::Left)
                    {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(w);
                        if (h->makeMove(mousePos.x, mousePos.y, b))
                        {
                            firstClick = true;
                        }
                    }
                }
            }
            else if(e.type == sf::Event::Resized){
                    w.setSize(targetSize);
            }
        }
        if(!firstClick){
        b->showSelection(w, xCord, yCord);
        shouldDraw = false;
        }
     
        
        w.display();
    }
    return 0;
}
