#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
//#include "Camara.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 450), "Juego"); // pantalla
    sf::Clock dre; // reloj
    

    Setup(window, sf::Vector2f (400.0f,225.0f));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) ///cerrar
                window.close();
            }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            mvel.x = -vel;
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            mvel.x = vel;
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            mvel.y = -vel;
        else{
            mvel.x = 0;
            mvel.y = 0;
        }
        float tiempo = dre.restart().asSeconds(); // tiempo 

        window.clear();

        Update(tiempo);
        Render(window);
        
        window.display();
        }
    return 0;
}
