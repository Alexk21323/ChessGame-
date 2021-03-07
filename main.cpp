#include <iostream>
#include <SFML/Graphics.hpp>
#include "board.h"
#include "piece.h"
#include "pawn.hpp"
#include "human.hpp"

int main(){
Board* b = new Board();
b->startGame();
Human* h = new Human();
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
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(w);
            h->move(mousePos.x, mousePos.y, b);
        }
    }
    }
    // for(int i = 0; i< 8; i++){
    //     for (int j = 0; j < 8; j++){
    //         std::cout << b->grids[j][i]->getPosition()[0] << 
    //         "  "<< b->grids[j][i]->getPosition()[1] <<"\n";
    //     }
    // }
    return 0;

}
