#pragma once

#include <string>
#include <glad/glad.h>
#include "math/math.h"

class Shader {
public:
    unsigned int ID;
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    
    void use();
    void setMat4(const std::string& name, const Mat4& mat);
    void setInt(const std::string& name, int value);
    
private:
    void checkCompileErrors(unsigned int shader, std::string type);
};

