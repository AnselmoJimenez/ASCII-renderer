#include "render.h"

#include "cube.h"

// determine the character to display based off of the face being rendered
char determine_cube_char(cube_t *cube, int cx, int cy, int cz) {
    if      (cz == -cube->depth)    return '@'; // front face
    else if (cy == -cube->height)   return '%'; // top face
    else if (cx == -cube->width)    return '+'; // right face
    else if (cz == cube->depth)     return '='; // back face
    else if (cy == cube->height)    return '#'; // bottom face
    else if (cx == cube->width)     return '/'; // left face

    // default
    return '.';
}

// render the cube
void render_cube_frame(cube_t *cube, float *z, char *out) {
    // preevaluate the values of cos(A) and sin(A)
    float cosA = cos(angle), sinA = sin(angle);

    // Z Coordinate
    for (float cz = -cube->depth; cz <= cube->depth; cz += COORD_INCREMENT) {
        // Y Coordinate 
        for (float cy = -cube->height; cy <= cube->height; cy += COORD_INCREMENT) {
            // X Coordinate
            for (float cx = -cube->width; cx <= cube->width; cx += COORD_INCREMENT) {
                // rotation calculations for coordinates
                float rx = cx*cosA*cosA + cy*cosA*sinA - cz*cosA*sinA + cy*cosA*sinA*sinA - cx*sinA*sinA*sinA;
                float ry = cz*sinA + cy*cosA*cosA - cx*cosA*sinA;
                float rz = cx*cosA*sinA + cy*sinA*sinA + cz*cosA*cosA - cy*cosA*cosA*sinA + cx*cosA*sinA*sinA + OBJECT_DISTANCE;

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
                        out[index] = determine_cube_char(cube, (int) roundf(cx), (int) roundf(cy), (int) roundf(cz));
                    }
                }
            }
        }
    }
}