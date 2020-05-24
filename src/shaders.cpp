#include <string>
#include <glad/glad.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include "shaders.h"

int vertexShader;
int fragShader;
int shaderProgram;

Shaders::Shaders(const char* vertPath, const char* fragPath){
    std::string vertCode;
    std::string fragCode;
    std::ifstream vShadFile;
    std::ifstream fShadFile;
    
    vShadFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShadFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    
    try{
        vShadFile.open(vertPath);
        fShadFile.open(fragPath);
        
        std::stringstream vShadStream, fShadStream;
        
        vShadStream << vShadFile.rdbuf();
        fShadStream << fShadFile.rdbuf();
        
        vShadFile.close();
        fShadFile.close();
        
        vertCode = vShadStream.str();
        fragCode = fShadStream.str();
    }
    catch(std::ifstream::failure &e){
        std::cerr << "ERROR IN READING FILE" << std::endl;
    }
    
    const char* vertexShaderSource = vertCode.c_str();
    const char* fragShaderSource = fragCode.c_str();
    
    unsigned int vertexShader, fragShader;

    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cerr << "Error!\n" << infoLog << std::endl;
    }
    
    fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShader, 1, &fragShaderSource, NULL);
    glCompileShader(fragShader);
    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(fragShader, 512, NULL, infoLog);
        std::cerr << "Error!\n" << infoLog << std::endl;
    }
    
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success){
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cerr << "Error!\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragShader);
}

void Shaders::Use(){
    glUseProgram(shaderProgram);
}

void Shaders::SetBool(const std::string &name, bool value) const{
    glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), (int)value);
}

void Shaders::SetInt(const std::string &name, int value) const{
    glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), value);
}

void Shaders::SetFloat(const std::string &name, float value) const{
    glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), value);
}

Shaders::~Shaders(){
    delete this;
}
