#include <iostream>
#include <SFML/Graphics.hpp>
#include "board.h"
#include "piece.h"

int main(){

Board* b = new Board();
sf::VideoMode v(800,800);
sf::RenderWindow w(v, "Chess");
Piece* p = new Piece();
b->setPiece(p);

while(w.isOpen()){
    w.clear();
    b->draw(w);
    //w.draw(p->getSprite());
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