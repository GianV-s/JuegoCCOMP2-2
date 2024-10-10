#pragma once
#include <SFML/Graphics.hpp>


// referencias de funciones

sf::CircleShape punto(15.0f, 360u);

sf::Vector2f mvel (0.0f, 0.0f);
float vel = 100.0f;

void Setup(const sf::Window& window, sf::Vector2f pos){
    
    
    punto.setOrigin(sf::Vector2f(punto.getRadius()/2, punto.getRadius()/2));
    punto.setPosition(pos);
}

void Update(float time){
    punto.move(mvel.x * time, mvel.y * time);
}

void Render(sf::RenderWindow& window){
    window.draw(punto);
}