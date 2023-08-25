#ifndef CUBE_H_
#define CUBE_H_

#define SPEED 0.02f
#define INCREMENT 0.3f

// cube type to track data of each cube
typedef struct {
    int width;
    int height; 
    int depth;
    int x;
    int y; 
    int z;
    rotation_t axis_rotation;
} cube_t;

// determine the character to display based off of the face being rendered
char determine_char(cube_t *cube, int cx, int cy, int cz);

// Render a frame of the cube
void render_cube_frame(cube_t *cube, float *z, char *out);

#endif