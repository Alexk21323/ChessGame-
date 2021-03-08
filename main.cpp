#include <iostream>
#include <SFML/Graphics.hpp>
#include "board.h"
#include "piece.h"
#include "pawn.hpp"
#include "human.hpp"

int main()
{
    sf::Texture square_texture;
    sf::Sprite square_sprite;
    square_texture.loadFromFile("Sprites/square.png");
    square_sprite.setTexture(square_texture);
    sf::Vector2f targetSizeCircle(100.0f, 100.0f);

    square_sprite.setScale(
        targetSizeCircle.x / square_sprite.getGlobalBounds().width,
        targetSizeCircle.y / square_sprite.getGlobalBounds().height);
    
    square_sprite.setPosition(0,0);

    Board *b = new Board();
    b->startGame();
    Human *h = new Human();
    sf::VideoMode v(1000, 800);
    sf::RenderWindow w(v, "Chess");
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
                        if(h->select(mousePos.x, mousePos.y, b))
                        {
                            firstClick = false;
                            shouldDraw = true;
                            xCord = mousePos.x/100;
                            yCord = mousePos.y/100;

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
        }
        if(!firstClick){
        b->showSelection(w, xCord, yCord);
        shouldDraw = false;
        }
        w.display();
    }
    return 0;
}
