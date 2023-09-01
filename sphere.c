#include "render.h"
#include "sphere.h"

// determine the character to display based off of the lumination
char determine_sphere_lumination(sphere_t *sphere, float sx, float sy, float sz) {
    // lighting direction
    int lx = 0;
    int ly = 1;
    int lz = -1;
    
    // surface normal vector
    float nx = sx / sphere->r;
    float ny = sy / sphere->r;
    float nz = sz / sphere->r;

    // lumination intensity based on surface normal and lighting direction
    // negated for indexing purposes
    int luminance = (int) -(nx*lx + ny*ly + nz*lz);
    return "0$#?!/:+~,."[luminance];
}

// Render a frame of the sphere
void render_sphere_frame(sphere_t *sphere, float *z, char *out) {
    // Theta angle between point at sphere surface and z plane
    for (float theta = 0.0f; theta < PI; theta += ANGLE_INCREMENT) {
        float cosT = cos(theta), sinT = sin(theta);
        // Phi angle between xy plane and positive x axis
        for (float phi = 0.0f; phi < 2 * PI; phi += ANGLE_INCREMENT) {
            float cosP = cos(phi), sinP = sin(phi);

            // calculating surface coordinates
            float sx = sphere->r * sinT * cosP;
            float sy = sphere->r * sinT * sinP;
            float sz = sphere->r * cosT + OBJECT_DISTANCE;

            float z_inv = 1.0f / sz;

            // calculating projection onto screen
            int x_projection = (int) (SCREEN_WIDTH / 2) + sx * FOV * z_inv * STRETCH;
            int y_projection = (int) (SCREEN_HEIGHT / 2) - sy * FOV * z_inv;

            // Get the index of the projection on the screen
            int index = x_projection + y_projection * SCREEN_WIDTH;
            
            // If we're inside the range of the screen...
            if (-1 < index && index < SCREEN_HEIGHT * SCREEN_WIDTH) {
                if (z_inv > z[index]) {
                    z[index] = z_inv;
                    out[index] = determine_sphere_lumination(sphere, sx, sy, sz);
                }
            }
        }
    }
}