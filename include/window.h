#ifndef WINDOW_H
#define WINDOW_H

void WindowHints();

void InitWindow();

void ProcessInput(GLFWwindow*);

void ClearScreen(vec4);

void RenderLoop();

void Terminate();
#endif