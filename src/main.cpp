#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <unistd.h>
#include "math/math.h"

std::string loadShadersSource(const std::string& filePath){
    std::ifstream file(filePath);
    if(!file.is_open()){
        std::cerr<<"Can not open file: "<<filePath<<std::endl;
        return "";
    }
    std::stringstream buffer;
    buffer<<file.rdbuf();
    return buffer.str();
}

int main() {
    Vec2 pos(100, 200);
        Vec2 speed(5, 10);
        Vec2 new_pos = pos + speed;
        std::cout << "Vec2 test: (" << new_pos.x << ", " << new_pos.y << ")" << std::endl;
    
    Mat4 translation = Mat4::translate(Vec3(50, -30, 0));
        std::cout << "Mat4 translation test (x, y, z): "
                  << translation.m[12] << ", "
                  << translation.m[13] << ", "
                  << translation.m[14] << std::endl;
    
    if(!glfwInit())
        return -1;
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
        
    GLFWwindow* Window = glfwCreateWindow(800,600,"MyEngine",NULL,NULL);
    
    if(!Window){
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(Window);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        return -1;
    }
    glViewport(0,0,800,600);
    
    std::string vertexShaderSource = loadShadersSource("src/shaders/basic.vert");
    std::string fragmentShaderSource = loadShadersSource("src/shaders/basic.frag");
    const char * vsSource = vertexShaderSource.c_str();
    const char * fsSource = fragmentShaderSource.c_str();
    
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vsSource,NULL);
    glCompileShader(vertexShader);
    
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fsSource,NULL);
    glCompileShader(fragmentShader);
    
    unsigned int shaderProgramm = glCreateProgram();
    glAttachShader(shaderProgramm, vertexShader);
    glAttachShader(shaderProgramm, fragmentShader);
    glLinkProgram(shaderProgramm);
    
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,
         0.0f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f
    };
    
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
    while(!glfwWindowShouldClose(Window)){
        
        glClearColor(0.1f, 0.2f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glUseProgram(shaderProgramm);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        glfwSwapBuffers(Window);
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}
