#ifndef SHADERS_H
#define SHADERS_H

#include <string>

typedef struct Shaders Shaders;

struct Shaders{
    Shaders(const char*, const char*);
    ~Shaders();\
    
    // int vertexShader;
    // int fragShader;
    int shaderProgram;
    
    void Use();
    
    void SetBool(const std::string &name, bool value) const;
    void SetInt(const std::string &name, int value) const;
    void SetFloat(const std::string &name, float value) const;
    
};

#endif 
