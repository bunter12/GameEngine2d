#pragma once

#include <cmath>

struct Vec3{
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
    
    Vec3() = default;
    
    Vec3(float x_val, float y_val, float z_val) : x(x_val), y(y_val), z(z_val) {}
    
    Vec3 operator+(const Vec3& other) const { return Vec3(x + other.x, y + other.y, z + other.z); }
    Vec3 operator-(const Vec3& other) const { return Vec3(x - other.x, y - other.y, z - other.z); }
    Vec3 operator*(float scalar) const { return Vec3(x * scalar, y * scalar, z * scalar); }
};
