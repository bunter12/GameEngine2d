#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main() {
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

    while(!glfwWindowShouldClose(Window)){
        
        glClearColor(0.1f, 0.2f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glfwSwapBuffers(Window);
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}
