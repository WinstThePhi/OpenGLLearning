#ifndef PONG_H
#define PONG_H

struct rackets{
    vec2 position[2];
    vec2 size[2];
    float velocity[2];
    
    void Draw(){DrawRectangle();}
    
    void Update(){
        position[0].y += velocity[0];
        position[1].y += velocity[1];
    }
    
    void Setup(){
        SetupRectangle(position[0], position[1], size[0], size[1]);
    }
};

typedef struct rackets rackets;

#endif 
