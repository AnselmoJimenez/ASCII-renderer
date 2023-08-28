#include "render.h"
#include "rotation.h"

#include "cone.h"

// Determines the character to put on the cone
char determine_cone_char(cone_t *cone, int cz) {
    if (cz == 0) return '@'; // bottom face
    return '%';
}

// Render a frame of the cone
void render_cone_frame(cone_t *cone, float *z, char *out) {
    // Z Coordinate
    for (float cz = 0; cz < cone->l; cz += COORD_INCREMENT) {
        // Y Coordinate
        for (float cy = -cone->r; cy < cone->r; cy += COORD_INCREMENT) {
            // X Coordinate
            for (float cx = -cone->r; cx < cone->r; cx += COORD_INCREMENT) {
                // calculate distance from origin to the coordinate
                float d = sqrt(cx*cx + cy*cy);

                // rotation calculations for coordinates
                float rx = rotate_x(cx, cy, cz, cone->rotation) + cone->x; 
                float ry = rotate_y(cx, cy, cz, cone->rotation) + cone->y; 
                float rz = rotate_z(cx, cy, cz, cone->rotation) + OBJECT_DISTANCE + cone->z; 

                float z_inv = 1.0f / rz;

                if (d <= cone->r - cz) {
                    // projections
                    int x_projection = (int) (SCREEN_WIDTH / 2) + rx * FOV * z_inv * STRETCH;
                    int y_projection = (int) (SCREEN_HEIGHT / 2) - ry * FOV * z_inv;

                    // Get the index of the projection on the screen
                    int index = x_projection + y_projection * SCREEN_WIDTH;
                    
                    // If we're inside the range of the screen...
                    if (-1 < index && index < SCREEN_HEIGHT * SCREEN_WIDTH) {
                        if (z_inv > z[index]) {
                            z[index] = z_inv;
                            out[index] = determine_cone_char(cone, (int) roundf(cz));
                        }
                    }
                }
            }
        }
    }
    
    // increment rotation
    cone->rotation->angle += cone->rotation->rotation_speed;
}