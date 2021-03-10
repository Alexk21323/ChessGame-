#include <iostream>
#include <SFML/Graphics.hpp>
#include "board.h"
#include "piece.h"

#include "pawn.hpp"
#include "undo.hpp"
#include "human.hpp"
#include "computer.hpp"

int main()
{
    sf::Text winner;
    sf::Font font;
    if (!font.loadFromFile("Sprites/Action_Man_Shaded.ttf"))
    {
        std::cout << "can't load font\n";
    }
    winner.setFont(font);
    winner.setFillColor(sf::Color(102, 102, 255));
    winner.setCharacterSize(100);
    sf::Text reset;
    reset.setFont(font);
    reset.setCharacterSize(50);
    reset.setFillColor(sf::Color(255, 51, 51));
    reset.setPosition(860, 500);
    reset.setString("RESET");

    sf::Text resetPrompt;
    resetPrompt.setFont(font);
    resetPrompt.setFillColor(sf::Color(102, 102, 255));
    resetPrompt.setCharacterSize(30);
    resetPrompt.setString("Reset To Start Again");
    resetPrompt.setPosition(400, 500);

    sf::Vector2u targetSize(1050, 800);
    sf::RenderWindow w(sf::VideoMode(1050, 800), "Chess");
    w.setSize(targetSize);
    bool player1 = true;
    bool firstClick = true;
    bool moveMade = false;
    int xCord;
    int yCord;
    int turn_count = 0;
    int mode;
    Board *b = new Board();
    b->startGame();
    Human *h = new Human();
    Computer *ai = new Computer();

    sf::Vector2u targetIntro(500, 500);
    sf::RenderWindow introScreen(sf::VideoMode(500, 500), "Chess");
    introScreen.setSize(targetIntro);
    sf::Text introPrompt;
    introPrompt.setFont(font);
    introPrompt.setFillColor(sf::Color(102, 102, 255));
    introPrompt.setCharacterSize(30);
    introPrompt.setString("Chess");
    introPrompt.setPosition(100, 100);

    sf::Text mode0;
    mode0.setFont(font);
    mode0.setFillColor(sf::Color(102, 102, 255));
    mode0.setCharacterSize(30);
    mode0.setString("P vs P");
    mode0.setPosition(100, 250);

    sf::Text mode1;
    mode1.setFont(font);
    mode1.setFillColor(sf::Color(102, 102, 255));
    mode1.setCharacterSize(30);
    mode1.setString("P vs C");
    mode1.setPosition(100, 400);

    while (introScreen.isOpen())
    {
        introScreen.clear();
        introScreen.draw(introPrompt);
        introScreen.draw(mode0);
        introScreen.draw(mode1);
        sf::Event e;
        while (introScreen.pollEvent(e))
        {
            if ((e.type == sf::Event::Closed))
            {
                introScreen.close();
            }
            else if (e.type == sf::Event::Resized)
            {
                introScreen.setSize(targetIntro);
            }
            else if (e.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(w);
                if (mousePos.x < 500 && mousePos.x > 0 && mousePos.y > 250 && mousePos.y < 300)
                {
                    mode = 0;
                    introScreen.close();
                }
                else if (mousePos.x < 500 && mousePos.x > 0 && mousePos.y > 380 && mousePos.y < 480)
                {
                    std::cout << "click" << std::endl;
                    mode = 1;
                    introScreen.close();
                }
            }
            introScreen.display();
        }
    }

    while (w.isOpen())
    {
        b->draw(w);
        w.draw(reset);
        if (b->gameStatus == 0)
        {
            sf::Sprite knight;
            if (!h->current_player)
            {
                knight = b->getBKnight();
                knight.setPosition(875, 200);
                w.draw(knight);
            }
            else
            {
                knight = b->getWKnight();
                knight.setPosition(875, 200);
                w.draw(knight);
            }
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

                            if (mode == 0)
                            {
                                if (h->makeMove(mousePos.x, mousePos.y, b))
                                {
                                    firstClick = true;
                                    turn_count++;
                                }
                            }
                            else if (mode == 1)
                            {
                                if (h->makeMove(mousePos.x, mousePos.y, b))
                                {
                                    std::vector<Piece *> tmpPieces;
                                    tmpPieces = ai->selectValidPieces(b);
                                    ai->makeMove(tmpPieces, b);
                                    h->current_player = true;
                                    turn_count += 2;
                                    firstClick = true;
                                }
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
                else if (e.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(w);
                    if (mousePos.x <= 980 && mousePos.x >= 860 && mousePos.y <= 550 && mousePos.y >= 500)
                    {
                        std::cout << "clicked" << std::endl;
                        delete b;
                        b = new Board();
                        b->startGame();
                        h->current_player = true;
                    }
                }
            }
            if (!firstClick)
            {
                b->showSelection(w, xCord, yCord);
            }
        }
        else
        {
            sf::Event e;
            while (w.pollEvent(e))
            {
                if ((e.type == sf::Event::Closed))
                {
                    w.close();
                }
                else if (e.type == sf::Event::Resized)
                {
                    w.setSize(targetSize);
                }
                else if (e.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(w);
                    if (mousePos.x <= 980 && mousePos.x >= 860 && mousePos.y <= 550 && mousePos.y >= 500)
                    {
                        delete b;
                        b = new Board();
                        b->startGame();
                        h->current_player = true;
                    }
                }
            }
            if (b->gameStatus == 1)
                winner.setString("White Wins!");
            if (b->gameStatus == 2)
                winner.setString("Black Wins!");
            winner.setPosition(150, 350);
            w.draw(resetPrompt);
            w.draw(winner);
        }
        w.display();
    }
    return 0;
}
