#include "render.h"
#include "cube.h"

// determine the character to display based off of the face being rendered
char determine_char(cube_t *cube, int cx, int cy, int cz) {
    if      (cz == -cube->depth)    return '@'; // front face
    else if (cy == -cube->height)   return '%'; // top face
    else if (cx == -cube->width)    return '$'; // right face
    else if (cz == cube->depth)     return '.'; // back face
    else if (cy == cube->height)    return '#'; // bottom face
    else if (cx == cube->width)     return '?'; // left face

    // default
    return '.';
}

// angle of rotation
static float A = 0;

// render the cube
void render_cube_frame(cube_t *cube, float *z, char *out) {
    float cosA = cos(A);
    float sinA = sin(A);

    // Z Coordinate
    for (float cz = -cube->depth; cz <= cube->depth; cz += INCREMENT) {
        // Y Coordinate 
        for (float cy = -cube->height; cy <= cube->height; cy += INCREMENT) {
            // X Coordinate
            for (float cx = -cube->width; cx <= cube->width; cx += INCREMENT) {
                // rotation calculations for X and Y rotation
                float rx = (cx*cosA - cz*sinA) + cube->x;
                float ry = (cy*cosA + cz*cosA*sinA + cx*sinA*sinA) + cube->y;
                float rz = (-cy*sinA + cz*cosA*cosA + cx*cosA*sinA) + OBJECT_DISTANCE + cube->z;
                float z_inv = 1.0f / rz;

                // projections
                int x_projection = (int) (SCREEN_WIDTH / 2) + rx * FOV * z_inv * STRETCH;
                int y_projection = (int) (SCREEN_HEIGHT / 2) - ry * FOV * z_inv;

                // Get the index of the projection on the screen
                int index = x_projection + y_projection * SCREEN_WIDTH;
                
                // If we're inside the range of the screen...
                if (-1 < index && index < SCREEN_HEIGHT * SCREEN_WIDTH) {
                    if (z_inv > z[index]) {
                        z[index] = z_inv;
                        out[index] = determine_char(cube, (int) roundf(cx), (int) roundf(cy), (int) roundf(cz));
                    }
                }
            }
        }
    }

    A += SPEED;
}