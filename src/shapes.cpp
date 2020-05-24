#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include "shaders.h"
#include "maths.h"
#include "shapes.h"

unsigned int VBO;
unsigned int VAO;
unsigned int EBO;

Shaders* shader;
//const char *vertexShaderSource = "#version 460 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"layout (location = 1) in vec3 aColor;\n"
//"out vec3 ourColor;"
//"void main()\n"
//"{\n"
//"gl_Position = vec4(aPos, 1.0f);\n"
//"ourColor = aColor;"
//"}\0";
//
//const char *fragmentShaderSource = "#version 460 core\n"
//"out vec4 FragColor;\n;"
//"in vec3 ourColor;\n"
//"void main()"
//"{\n"
//"FragColor = vec4(ourColor, 1.0);\n"
//"}\0";

void DrawTriangle(){
    //glUseProgram(shaderProgram);
    shader->Use();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void SetupTriangle(){
    shader = new Shaders("shaders/vertex.vs", "shaders/frag.fs");
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f
    };
    
    glGenBuffers(1, &VBO);
    
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
}

void UpdateRectangle(vec2 pos1, vec2 pos2, vec2 size1, vec2 size2){
    glBindBuffer(GL_ARRAY_BUFFER, VAO);
    float vertices[]= {
        pos1.x, pos1.y, 0.0f,
        pos1.x + size1.x, pos1.y, 0.0f,
        pos1.x + size1.x, pos1.y - size1.y, 0.0f,
        pos1.x, pos1.y - size1.y, 0.0f,
        pos2.x, pos2.y, 0.0f,
        pos2.x + size2.x, pos2.y, 0.0f,
        pos2.x + size2.x, pos2.y - size2.y, 0.0f,
        pos2.x, pos2.y - size2.y, 0.0f
    };
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), &vertices);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void DrawRectangle(){
    //glUseProgram(shaderProgram);
    //shader.Use();
    glBindVertexArray(VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
}

void SetupRectangle(vec2 pos1, vec2 size1, vec2 pos2, vec2 size2){
    float vertices[]= {
        pos1.x, pos1.y, 0.0f,
        pos1.x + size1.x, pos1.y, 0.0f,
        pos1.x + size1.x, pos1.y - size1.y, 0.0f,
        pos1.x, pos1.y - size1.y, 0.0f,
        pos2.x, pos2.y, 0.0f,
        pos2.x + size2.x, pos2.y, 0.0f,
        pos2.x + size2.x, pos2.y - size2.y, 0.0f,
        pos2.x, pos2.y - size2.y, 0.0f
    };
    
    unsigned int indices[] = {
        0, 1, 2,
        0, 2, 3,
        4, 5, 6,
        4, 6, 7,
    };
    
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

/*void SetupShape(SHAPES shape){
    switch(shape){
        case RECTANGLE:
        SetupRectangle();
        break;
        case TRIANGLE:
        SetupTriangle();
        break;
        default:
        std::cerr << "Error: no such shape" << std::endl;
        break;
    }
}

void DrawShape(SHAPES shape){
    switch(shape){
        case RECTANGLE:
        DrawRectangle();
        case TRIANGLE:
        DrawTriangle();
        default:
        std::cerr << "Error: no such shape" << std::endl;
    }
}*/
