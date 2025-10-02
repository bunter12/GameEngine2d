#pragma once

#include "shaders.h"
#include "math/math.h"

class SpriteRenderer{
private:
    Shader& shader;
    unsigned int quadVAO;
    
    void initRenderData();
public:
    SpriteRenderer(Shader& shader);
    ~SpriteRenderer();
    
    void DrawSprite(unsigned int textureID, Vec2 position, Vec2 size = Vec2(10,10), float rotate=0.0f);
};
