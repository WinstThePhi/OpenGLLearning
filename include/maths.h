#ifndef MATHS_H
#define MATHS_H

struct vec2{
    float x;
    float y;
    
    /*vec2(float a, float b){
        x = a;
        y = b;
    }*/
};

typedef struct vec2 vec2;

struct vec3{
    float x;
    float y;
    float z;
    
    /*vec3(float a, float b, float c){
        x = a;
        y = b;
        z = c;
    }*/
};

typedef struct vec3 vec3;

struct vec4{
    float x;
    float y;
    float z;
    float w;
    
    /*vec4(float a, float b, float c, float d){
        x = a;
        y = b;
        z = c;
        w = d;
    }*/
};

typedef struct vec4 vec4;

#endif