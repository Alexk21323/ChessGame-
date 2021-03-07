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
    sf::VideoMode v(1000, 800);
    sf::RenderWindow w(v, "Chess");
    bool player1 = true;
    bool firstClick = true;
    bool moveMade = false;
    while (w.isOpen())
    {
        w.clear();
        b->draw(w);
        w.display();
        sf::Event e;
        int tmpCoorX;
        int tmpCoorY;
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
                        tmpCoorX = mousePos.x / 100;
                        tmpCoorY = mousePos.y / 100;
                        if (h->select(mousePos.x, mousePos.y, b))
                        {
                            firstClick = false;
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
    }

    return 0;
}
