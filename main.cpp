#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800, 450), "Juego"); // pantalla
    Clock dre; // reloj
    CircleObject circ1(10.0f, 360u, Vector2f(0.0f,0.0f));

    array<int,4> coord = {40, 80, 40, 80};
    BoxObject caja1(&coord[0]);

    vector<RectangleShape> cajes;
    cajes.push_back(caja1.getRect());

    vector<CircleShape> puntos;
    puntos.push_back(circ1.getCirc());

    Setup(window, Vector2f (400.0f,225.0f));
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) ///cerrar
                window.close();
            }

        if(Keyboard::isKeyPressed(Keyboard::A)) // movimiento s
            mvel.x = -vel;
        else if(Keyboard::isKeyPressed(Keyboard::D))
            mvel.x = vel;
        else if(Keyboard::isKeyPressed(Keyboard::Space))
            mvel.y = -vel;
        else{
            mvel.x = 0;
            mvel.y = 0;
        }
        float tiempo = dre.restart().asSeconds(); // tiempo 

        window.clear();

        Update(tiempo);
        Render(window, cajes, puntos);
        
        window.display();
        }
    return 0;
}
