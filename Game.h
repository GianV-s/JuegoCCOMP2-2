#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include <iostream>
#include "World.h"

using namespace std;


// referencias de funciones

sf::CircleShape punto(15.0f, 360u);

sf::Vector2f mvel (0.0f, 0.0f);

float vel = 100.0f;

void apendice(vector<BoxObject>, vector<CircleObject>);



void Setup(const sf::Window& window, sf::Vector2f pos){
    punto.setOrigin(sf::Vector2f(punto.getRadius()/2, punto.getRadius()/2));
    punto.setPosition(pos);
}

void Update(float time){
    punto.move(mvel.x * time, mvel.y * time);
    
}

void Render(sf::RenderWindow& window, vector<sf::RectangleShape> cajes, vector<sf::CircleShape> puntos){
    window.draw(punto);
    for(int i = 0; i < cajes.size(); i++){
        window.draw(cajes[i]);
    }
}