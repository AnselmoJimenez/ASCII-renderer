#include "render.h"
#include "cube.h"

// angle of rotation
static float A = 0;

// calculate and assign character to each face of the cube
float calculate_face(float cx, float cy, float cz, char character);

// render the cube
void render_cube_frame(cube_t *cube, float *z, char *out) {
    float cosA = cos(A);
    float sinA = sin(A);

    // X coordinate
    for (float cy = -cube->height; cy < cube->height; cy += INCREMENT) {
        // Y coordinate
        for (float cx = -cube->width; cx < cube->width; cx += INCREMENT) {
            // rotation calculations
            float rx = cx*cosA;
            float ry = cy*cosA + cx*sinA*sinA;
            float rz = -cy*sinA + cx*cosA*sinA + OBJECT_DISTANCE;
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

                    out[index] = '#';
                }
            }
        }
    }

    A += SPEED;
}