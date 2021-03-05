#include <iostream>
#include <SFML/Graphics.hpp>
#include "board.h"
#include "piece.h"
#include "pawn.hpp"

int main(){
Board* b = new Board();
b->startGame();
sf::VideoMode v(800,800);
sf::RenderWindow w(v, "Chess");

while(w.isOpen()){
    w.clear();
    b->draw(w);
    w.display();
    sf::Event e;
    while(w.pollEvent(e)){
        if((e.type== sf::Event::Closed)){
            w.close();
        }
    }
    }
    return 0;
}
