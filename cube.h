#ifndef CUBE_H_
#define CUBE_H_

#include <stdbool.h>

#define SPEED 0.05f
#define INCREMENT 0.05f

// cube type to track data of each cube
typedef struct {
    float width;
    float height; 
    float depth;
    int x;
    int y; 
    int z;
    bool rotation;
} cube_t;

// Render a frame of the cube
void render_cube_frame(cube_t *cube, float *z, char *out);

#endif