#include "chip8.h"

#include <SFML/Graphics.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(64, 32), "Chip-8 Emu");

    while(window.isOpen())
    {

        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color::Black);

        window.display();
    }
    return 0;
}
