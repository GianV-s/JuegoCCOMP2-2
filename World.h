#include "Game.h"


class BoxObject{
    public:
    explicit BoxObject(int* cptr){ /*is - ds - ii - di
    (is)-------------(ds)      
    (ii)-------------(di)
    */
        sf::IntRect BoxCollider(*cptr, *cptr + 1, *cptr + 2, *cptr + 3);
        rect.setSize(sf::Vector2f(static_cast<float>(*cptr - (*cptr + 1)), static_cast<float>(*cptr - (*cptr + 2))));
        rect.setOrigin(sf::Vector2f(rect.getSize().x/2, rect.getSize().y/2));
    }

    bool isBoxCol(IntRect a, IntRect b){
        if(a.intersects(b))
        return true;
        else
        return false;
    }

    RectangleShape getRect(){
        return rect;
    }
    private: 
    //sprite
    sf::RectangleShape rect;//drwa
    sf::IntRect BoxCollider;//collison
    //array<int,4> coords;

};

class CircleObject{
    public:
    explicit CircleObject(float r, int u, sf::Vector2f pos){
        sf::CircleShape circ (10.0f, 360u);
        circ.setOrigin(5.0f, 5.0f);
        circ.setPosition(0.0f,0.0f);
    }

    sf::CircleShape getCirc(){
        return circ;
    }    

    private:
    sf::CircleShape circ;
    //collisione
    };