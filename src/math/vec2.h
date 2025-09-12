#pragma once

#include <cmath>

struct Vec2{
    float x = 0.0f;
    float y = 0.0f;
    
    Vec2() = default;
    
    Vec2(float x_val, float y_val): x(x_val), y(y_val) {}
    
    Vec2 operator+(const Vec2& other) const { return Vec2(x + other.x, y + other.y); }
    Vec2 operator-(const Vec2& other) const { return Vec2(x - other.x, y - other.y); }
    Vec2 operator*(float scalar) const { return Vec2(x * scalar, y * scalar); }
};
