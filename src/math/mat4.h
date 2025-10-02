#pragma once

#include <cmath>
#include <cstring>
#include "vec3.h"


struct Mat4{
    float m[16];
    
    Mat4(){
        memset(m,0,sizeof(m));
        m[0] = 1.0f;
        m[5] = 1.0f;
        m[10] = 1.0f;
        m[15] = 1.0f;
    }
    
    static Mat4 translate(const Vec3& vector){
        Mat4 result;
        result.m[12] = vector.x;
        result.m[13] = vector.y;
        result.m[14] = vector.z;
        
        return result;
    }
    
    static Mat4 ortho(float left, float right, float bottom, float top, float near_plane, float far_plane){
        Mat4 result;
        
        result.m[0] = 2.0f / (right - left);
        result.m[5] = 2.0f / (top - bottom);
        result.m[10] = -2.0f / (far_plane - near_plane);
        result.m[12] = -(right + left) / (right - left);
        result.m[13] = -(top + bottom) / (top - bottom);
        result.m[14] = -(far_plane + near_plane) / (far_plane - near_plane);
        
        return result;
    }
    
    static Mat4 scale(const Vec3& v){
        Mat4 result;
        
        result.m[0] = v.x;
        result.m[5] = v.y;
        result.m[10] = v.z;
        
        return result;
    }
    
    static Mat4 rotate(float angle_degrees, const Vec3& axis) {
        Mat4 result;
        float angle_rad = angle_degrees * 3.1415926535f / 180.0f;
        float c = cosf(angle_rad);
        float s = sinf(angle_rad);
        
        float x = axis.x, y = axis.y, z = axis.z;
        float t = 1.0f - c;

        result.m[0] = t*x*x + c;
        result.m[1] = t*x*y + s*z;
        result.m[2] = t*x*z - s*y;

        result.m[4] = t*x*y - s*z;
        result.m[5] = t*y*y + c;
        result.m[6] = t*y*z + s*x;
        
        result.m[8] = t*x*z + s*y;
        result.m[9] = t*y*z - s*x;
        result.m[10] = t*z*z + c;

        return result;
    }
    
    
    Mat4 operator*(const Mat4& other) const {
        Mat4 result;

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                float sum = 0.0f;
                for (int k = 0; k < 4; ++k){
                    sum += m[k * 4 + j] * other.m[i * 4 + k];
                }
                result.m[i * 4 + j] = sum;
            }
        }
        return result;
    }
};
