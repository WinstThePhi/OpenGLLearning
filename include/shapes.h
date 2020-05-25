#ifndef SHAPES_H
#define SHAPES_H

/*enum SHAPES{
    TRIANGLE,
    RECTANGLE
};*/
#include "shaders.h"

extern Shaders* shader;

void CreateShaderProgram();

void CreateShaders();

void DrawTriangle();

void SetupTriangle();

void UpdateRectangle(vec2, vec2, vec2, vec2);

void DrawRectangle();

void SetupRectangle();

void SetupTextures();

//void SetupShape(SHAPES shape);

//void DrawShape(SHAPES shape);

#endif