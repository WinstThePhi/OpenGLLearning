#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "maths.h"
#include "shapes.h"
//#include "pong.h"
#include "window.h"

GLFWwindow *window;
const unsigned int WIDTH = 1000, HEIGHT = 750;

vec4 clearColor{0.2f, 0.3f, 0.3f, 1.0f};

void WindowHints(){
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void InitWindow(){
    if(!glfwInit()){
        std::cerr << "GLFW failed to initialize!" << std::endl;
        return;
    }
    WindowHints();
    window = glfwCreateWindow(WIDTH, HEIGHT, "Learn OpenGL", NULL, NULL);
    if(window == NULL){
        std::cerr << "Window failed to initialize" << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cerr << "Glad failed to initialize" << std::endl;
        return;
    }
    glViewport(0, 0, WIDTH, HEIGHT);
}


void ProcessInput(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
}

void ClearScreen(vec4 color){
    glClearColor(color.x, color.y, color.z, color.w);
    glClear(GL_COLOR_BUFFER_BIT);
}

void RenderLoop(){
    /*vec2 pos1{-0.9f, 0.2f};
    vec2 size1{0.05f, 0.4f};
    vec2 pos2{0.85f, 0.2f};
    vec2 size2{0.05f, 0.4f};*/
    SetupTriangle();
    while(!glfwWindowShouldClose(window)){
        ProcessInput(window);
        ClearScreen(clearColor);
        DrawTriangle();
        glfwSwapInterval(1);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Terminate(){
    glfwTerminate();
    shader->~Shaders();
}