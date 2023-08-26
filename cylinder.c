#include "render.h"
#include "rotation.h"

#include "cylinder.h"

// Determines the character to put on the cylinder
char determine_cylinder_char(cylinder_t *cylinder, int cz) {
    if      (cz == -cylinder->l)    return '@'; // front face
    else if (cz == cylinder->l)     return '?'; // left face

    return '%';
}

// Render a frame of the cylinder
void render_cylinder_frame(cylinder_t *cylinder, float *z, char *out) {
    // Z Coordinate
    for (float cz = -cylinder->l; cz <= cylinder->l; cz += COORD_INCREMENT) {
        // Y Coordinate
        for (float cy = -cylinder->r; cy <= cylinder->r; cy += COORD_INCREMENT) {
            // X Coordinate
            for (float cx = -cylinder->r; cx <= cylinder->r; cx += COORD_INCREMENT) {
                // calculate distance from origin to the coordinate
                float d = sqrt(cx*cx + cy*cy);

                // rotation calculations for coordinates
                float rx = rotate_x(cx, cy, cz, cylinder->rotation) + cylinder->x; 
                float ry = rotate_y(cx, cy, cz, cylinder->rotation) + cylinder->y; 
                float rz = rotate_z(cx, cy, cz, cylinder->rotation) + OBJECT_DISTANCE + cylinder->z; 

                float z_inv = 1.0f / rz;

                if (d <= cylinder->r) {
                    // projections
                    int x_projection = (int) (SCREEN_WIDTH / 2) + rx * FOV * z_inv * STRETCH;
                    int y_projection = (int) (SCREEN_HEIGHT / 2) - ry * FOV * z_inv;

                    // Get the index of the projection on the screen
                    int index = x_projection + y_projection * SCREEN_WIDTH;
                    
                    // If we're inside the range of the screen...
                    if (-1 < index && index < SCREEN_HEIGHT * SCREEN_WIDTH) {
                        if (z_inv > z[index]) {
                            z[index] = z_inv;
                            out[index] = determine_cylinder_char(cylinder, (int) roundf(cz));
                        }
                    }
                }
            }
        }
    }
    
    // increment rotation
    cylinder->rotation->angle += cylinder->rotation->rotation_speed;
}