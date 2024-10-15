// implementaciones de funciones

#include "Game.h"

sf::CircleShape punto(300.0f);

void Setup(const sf::Window& window, sf::Vector2f pos){
    punto.setOrigin(sf::Vector2f(punto.getRadius()/2, punto.getRadius()/2));
    punto.setPosition(pos);
}

void Update(float time){

}

void Render(sf::RenderWindow& window){
    window.draw(punto);
}