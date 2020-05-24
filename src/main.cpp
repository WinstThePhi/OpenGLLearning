#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "maths.h"
#include "window.h"

int main(){
    InitWindow();
    RenderLoop();
    Terminate();
    return 0;
}

