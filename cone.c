#include "render.h"

#include "cone.h"

// Determines the character to put on the cone
char determine_cone_char(cone_t *cone, int cz) {
    if (cz == -cone->l) return '@'; // bottom face
    return '%';
}

// Render a frame of the cone
void render_cone_frame(cone_t *cone, float *z, char *out) {
    // preevaluate sin and cosine values for angles
    float cosA = cos(angle), sinA = sin(angle);

    // radius trackers as we iterate through the z axis
    float r_decrement = cone->r / (4*cone->l);
    int l_pos = 0;

    // Z Coordinate
    for (float cz = -cone->l; cz < cone->l; cz += COORD_INCREMENT) {
        // Y Coordinate
        for (float cy = -cone->r; cy < cone->r; cy += COORD_INCREMENT) {
            // X Coordinate
            for (float cx = -cone->r; cx < cone->r; cx += COORD_INCREMENT) {
                // calculate distance from origin to the coordinate
                float d = sqrt(cx*cx + cy*cy);

                // rotation calculations for coordinates
                float rx = cx*cosA*cosA + cy*cosA*sinA - cz*cosA*sinA + cy*cosA*sinA*sinA - cx*sinA*sinA*sinA;
                float ry = cz*sinA + cy*cosA*cosA - cx*cosA*sinA;
                float rz = cx*cosA*sinA + cy*sinA*sinA + cz*cosA*cosA - cy*cosA*cosA*sinA + cx*cosA*sinA*sinA + OBJECT_DISTANCE; 

                float z_inv = 1.0f / rz;
                
                if (d <= cone->r - (r_decrement * l_pos)) {
                    // projections
                    int x_projection = (int) (SCREEN_WIDTH / 2) + rx * FOV * z_inv * STRETCH;
                    int y_projection = (int) (SCREEN_HEIGHT / 2) - ry * FOV * z_inv;

                    // Ge>t the index of the projection on the screen
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
        l_pos++;
    }
}