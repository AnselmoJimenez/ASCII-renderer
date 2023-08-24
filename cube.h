#ifndef CUBE_H_
#define CUBE_H_

#define SPEED 0.02f
#define INCREMENT 0.5f

// cube type to track data of each cube
typedef struct {
    float width;
    float height; 
    float depth;
    int x;
    int y; 
    int z;
} cube_t;

// determine the character to display based off of the face being rendered
char determine_char(cube_t *cube, float cx, float cy, float cz)

// Render a frame of the cube
void render_cube_frame(cube_t *cube, float *z, char *out);

#endif