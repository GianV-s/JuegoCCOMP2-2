#include "Game.h"

using namespace sf;

class BoxCollider{
public:
explicit BoxCollider (FloatRect Bounds = FloatRect(Vector2f(0.0f,0.0f), Vector2f(0.0f,0.0f))) : Collider{Bounds}{
}

bool isColliding(BoxCollider otro){
    Vector2f estePos = Collider.getPosition();
    Vector2f este_ofs(estePos.x + Collider.width / 2, estePos.y + Collider.height / 2);
    Vector2f otroPos = Collider.getPosition();
    Vector2f otro_ofs(otroPos.x + otro.Collider.width / 2, otroPos.y + otro.Collider.height / 2);

    float dx = estePos.x - otroPos.x;
    float dy = estePos.y - otroPos.y;
    float intx = abs(dx) - (este_ofs.x + otro_ofs.x);
    float inty = abs(dy) - (este_ofs.y + otro_ofs.y);

    if (intx < 0.0f && inty < 0.0){
        return true;
    }
    else{
        return false;
    }
}



void setBounds(FloatRect rect){
    Collider = rect;
}

private:
FloatRect Collider;
};