#include <iostream>
#include <SFML/Graphics.hpp>
#include "board.h"
#include "piece.h"
#include "pawn.hpp"
#include "undo.hpp"
#include "human.hpp"

int main()
{
    Board *b = new Board();
    b->startGame();
    Human *h = new Human();
    sf::Vector2u targetSize(1050, 800);
    sf::RenderWindow w(sf::VideoMode(1050, 800), "Chess");
    w.setSize(targetSize);
    bool player1 = true;
    bool firstClick = true;
    bool moveMade = false;
    int xCord;
    int yCord;
    int turn_count = 0;
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
                        if (mousePos.x / 100 <= 7 && mousePos.x / 100 >= 0 && mousePos.y / 100 >= 0 && mousePos.y / 100 <= 7)
                        {
                            if (h->select(mousePos.x, mousePos.y, b))
                            {
                                firstClick = false;
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
                            turn_count++;
                        }
                    }
                }
                if (e.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(w);
                    if (mousePos.x <= 965 && mousePos.x >= 875 && mousePos.y <= 700 && mousePos.y >= 600)
                    {
                        std::cout << "clicked undo\n";
                        std::cout << turn_count << std::endl;
                        Undo *u;
                        u->undo(b);
                        if (turn_count != 0)
                            h->current_player = !h->current_player;
                        if (turn_count > 0)
                            turn_count--;
                    }
                }
            }
            else if (e.type == sf::Event::Resized)
            {
                w.setSize(targetSize);
            }
        }
        if (!firstClick)
        {
            b->showSelection(w, xCord, yCord);
        }
        w.display();
    }
    return 0;
}
