#include "Vec2.hpp"

Vec2::Vec2(){};

Vec2::Vec2(float xin, float yin) : x(xin), y(yin){
    // nothing to do else
    // only initializer list
}

// member functions

float Vec2::dist(const Vec2& v) const {
    //distance between to points
    return std::sqrtf((v.x-x)*(v.x-x) + (v.y-y)*(v.y-y));
}

Vec2& Vec2::add(const Vec2& v){
    x += v.x;
    y += v.y;
    return *this;
}

Vec2& Vec2::scale(float s){
    // scale this vector by s
    x *= s;
    y *= s;
    return *this;
}

Vec2& Vec2::rotate(float deg){
    // rotate this vector by deg
    return *this;
}

// overloads
bool Vec2::operator== (const Vec2& rhs) const {
    return (x == rhs.x && y == rhs.y) ? true : false;
}

Vec2 Vec2::operator+ (const Vec2& rhs) const {
    return Vec2(x + rhs.x, y + rhs.y);
}

Vec2 Vec2::operator* (const Vec2& rhs) const {
    return *this;
}

void Vec2::operator+= (const Vec2& rhs){
    x += rhs.x;
    y += rhs.y;
}
