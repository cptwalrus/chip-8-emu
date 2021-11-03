#include "chip8.h"

#include <SFML/Graphics.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(64, 32), "Chip-8 Emu");

    Chip8 chip8;

    sf::Texture texture;
    texture.create(64, 32);

    sf::Sprite sprite(texture);

    while(window.isOpen())
    {
        for(int pixel = 0; pixel < chip8.gfx.size(); pixel+=4)
        {
          chip8.gfx[pixel] = 255;
          chip8.gfx[pixel+1] = 255;
          chip8.gfx[pixel+2] = 255;
          chip8.gfx[pixel+3] = 255;
            
        }

        texture.update(chip8.gfx.data());

        window.draw(sprite);

        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        //window.clear(sf::Color::Black);
        window.display();
    }
    return 0;
}
