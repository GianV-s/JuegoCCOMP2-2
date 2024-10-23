#include <SFML/Graphics.hpp>
#include "Game.h"
using namespace sf;

class Player : public CircleShape {
public:
    explicit Player(float radio, unsigned int pointCount, int _hp, Vector2f _pos, float _vel = 150.f)
        : CircleShape(radio, pointCount), hp{_hp}, pos{_pos}, vel{_vel}, 
          collisione{Collider(_pos, CircleShape(radio, pointCount))} {
        setOrigin(radio , radio);
        setFillColor(Color(250, 200, 250));
        setPosition(pos);
    }

    // This function updates the collider's position to match the player's position
    void Update() {
        // Update the collider's position to the current player's position
        collisione.setPos(getPosition());
    }

    void movePlayer(float deltaTime) {
        Vector2f mvel(0.f, 20.f); // Gravity effect

        // Movement logic
        if (Keyboard::isKeyPressed(Keyboard::A)) {
            mvel.x = -vel; // Move left
        }
        if (Keyboard::isKeyPressed(Keyboard::D)) {
            mvel.x = vel; // Move right
        }
        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            //Jump(); // Jump logic
        }

        // Move the player and immediately update the collider
        move(mvel * deltaTime);
        Update();  // Ensure the collider follows the player
    }

    void checkBorder(int scw, int sch) {
        if (getPosition().x + getRadius() > scw) {  // Right border
            setPosition(scw - getRadius(), getPosition().y);
        } 
        else if (getPosition().x - getRadius() < 0) {  // Left border
            setPosition(0 + getRadius(), getPosition().y);
        }

        if (getPosition().y + getRadius() > sch) {  // Bottom border
            setPosition(getPosition().x, sch - getRadius());
            //isGrounded = true;  // Player grounded when hitting the bottom
        } 
        else if (getPosition().y - getRadius() < 0) {  // Top border
            setPosition(getPosition().x, 0 + getRadius());
        }

        // Update the collider's position after border checks
        Update();
    }

    // Get the player's collider object
    Collider getCollider() {
        return collisione;
    }

private:
    int hp;                  // Player's health points
    Vector2f pos;            // Player's position
    float vel;               // Player's movement speed
    Collider collisione;     // Player's collider object
};
