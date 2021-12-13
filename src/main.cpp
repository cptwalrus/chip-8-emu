#include "chip8.h"

#include <SFML/Graphics.hpp>
#include <fstream>

#include <iostream>

int main()
{
    //basically all of this code is filler code for testing...
    
    std::ifstream stream("src/ibmlogo.ch8", std::ios::binary);
    if (!stream.is_open()) 
    {
        std::cout << "STREAM FAILED TO OPEN!" << std::endl;
        return 1;
    }


    sf::RenderWindow window(sf::VideoMode(64, 32), "Chip-8 Emu");

    Chip8 chip8;

    stream.seekg(0, stream.end);
    auto size = stream.tellg();
    stream.seekg(0, stream.beg);
    stream.read(reinterpret_cast<char*>(&chip8.memory[0x200]), size);

    std::cout << "Reading in " << size << " from rom" << std::endl;

    sf::Texture texture;
    texture.create(64, 32);

    sf::Sprite sprite(texture);

    while(window.isOpen())
    {

        texture.update(chip8.gfx.data());

        window.draw(sprite);

        chip8.emulateCycle();
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.display();
    }
    return 0;
}
