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
};
