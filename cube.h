#ifndef CUBE_H_
#define CUBE_H_

// cube type to track data of each cube
typedef struct {
    int width;
    int height; 
    int depth;
} cube_t;

// Rotate the coordinates on XYZ and put the cooresponding character
void rotate_surface(float rx, float ry, float rz, char c, float *z_buf, char *out_buf);

// render a single frame of the cube at the current angle
void render_cube_frame(cube_t *cube, float *z_buf, char *out_buf);

#endif