#pragma once
#include <cmath>
#include <iostream>

class Vec2 {
    public:
        // members
        float x = 0;
        float y = 0;

        // constructors
        Vec2();
        Vec2(float xin, float yin);

        // member functions
        float dist(const Vec2& v) const;
        Vec2& add(const Vec2& v);
        Vec2& scale(float s);
        Vec2& rotate(float deg);

        // operators
        bool operator == (const Vec2& rhs) const;
        bool operator != (const Vec2& rhs) const;

        Vec2 operator + (const Vec2& rhs) const;
        Vec2 operator - (const Vec2& rhs) const;
        Vec2 operator * (const Vec2& rhs) const;
        Vec2 operator / (const Vec2& rhs) const;

        void operator += (const Vec2& rhs);
        void operator -= (const Vec2& rhs);
        void operator *= (const Vec2& rhs);
        void operator /= (const Vec2& rhs);

};
