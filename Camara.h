#pragma once
#include <SFML\Graphics.hpp>

class Camara {
public:
    Camara::Camara(float zoom)
        : zoom(zoom){}
    
    Camera(float zoom = 5.0f);
    sf::View GetView(sf::Vector2u windowSize);

    float zoom;
};
