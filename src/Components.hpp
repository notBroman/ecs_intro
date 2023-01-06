#pragma once

#include <SFML/Graphics.hpp>

#include "Vec2.hpp"

/*
 * These classes are pure data and are attached to an entity
 *
 */
class CTransform{
pubilc:
    Vec2 pos = {0.0, 0.0};
    Vec2 velocity = {0.0, 0.0};
    float angle = 0;

    CTransform(const Vec2& p, const Vec2& v, float deg)
        : pos(p), velocity(v), angle(deg) {
    }
};

class CName{
public:
    std::string name = "Default";

    CName(std::string n) : name(n){
    }
};

class CShape{
public:
    sf::CircleShape circle;

    CShape(float radius, int points, const sf::Color& fill,
            const sf::Color& outline, float thickness)
        : circle(radius, points)
    {
        circle.setFillColor(fill);
        circle.setOutlineColor(outline);
        circle.setOutlineThickness(thickness);
        circle.setOrigin(radius, radius);
    }
};

class CHealth{
public:
    float health = 100;

    CHealth(float h) : health(health) {
    }
};

class CDamage{
public:
    float dmg = 0;

    CDamage(float d) : dmg(d){
    }
};

class CCollision{
public:
    float radius = 0;

    CCollision(float r) : radius(r) {
    }
};

class CInput{
public:
    bool up = false;
    bool left = false;
    bool right = false;
    bool down = false;
    bool shoot = false;

    CInput() {}

};

class CLifespan{
public:
    int remaining = 0; // how much time is left
    int total = 0; // total time it is alive

    CLifespan(int t) : remaining(t), total(t){
    }
};
