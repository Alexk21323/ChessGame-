#include <iostream>
#include <SFML/Graphics.hpp>
#include "board.h"
#include "piece.h"

int main(){

Board* b = new Board();
sf::VideoMode v(1000,1000);
sf::RenderWindow w(v, "Chess");
Piece* p = new Piece();
p->setTexture("Sprites/bking.png");
p->setSprite();
p->setSize();


while(w.isOpen()){
    w.clear();
    w.draw(b->getSprite());
    w.draw(p->getSprite());
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