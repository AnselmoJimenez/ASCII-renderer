#include "render.h"
#include "sphere.h"

// determine the character to display based off of the lumination
char illuminate(sphere_t *sphere, float sx, float sy, float sz) {
    // lighting direction
    float lx = 0.0f;
    float ly = -0.707f;
    float lz = 0.707f;
    
    // surface normal vector
    float nx = sx / sphere->r;
    float ny = sy / sphere->r;
    float nz = sz / sphere->r;

    // lumination intensity based on surface normal and lighting direction
    // negated for because what is shown is the sphere
    float luminance = (nx*lx + ny*ly + nz*lz) * 8;
    if (luminance < 0) luminance *= -1;
    return ".,:;=#$@"[(int) luminance];
}

// Render a frame of the sphere
void render_sphere_frame(sphere_t *sphere, float *z, char *out) {
    // Preevaluate sin and cos of angles
    float cosA = cos(angle), sinA = sin(angle);

    // Theta angle between point at sphere surface and z plane
    for (float theta = 0.0f; theta < PI; theta += ANGLE_INCREMENT) {
        float cosT = cos(theta), sinT = sin(theta);
        // Phi angle between xy plane and positive x axis
        for (float phi = 0.0f; phi < 2 * PI; phi += ANGLE_INCREMENT) {
            float cosP = cos(phi), sinP = sin(phi);

            // calculating surface coordinates
            float sx = sphere->r * sinT * cosP;
            float sy = sphere->r * sinT * sinP;
            float sz = sphere->r * cosT;

            // rotating surface coordinates
            // XYZ rotations
            float rx = sx*cosA*cosA + sy*cosA*sinA - sz*cosA*sinA + sy*cosA*sinA*sinA - sx*sinA*sinA*sinA;
            float ry = sz*sinA + sy*cosA*cosA - sx*cosA*sinA;
            float rz = sx*cosA*sinA + sy*sinA*sinA + sz*cosA*cosA - sy*cosA*cosA*sinA + sx*cosA*sinA*sinA + OBJECT_DISTANCE;

            float z_inv = 1.0f / rz;

            // calculating projection onto screen
            int x_projection = (int) (SCREEN_WIDTH / 2) + rx * FOV * z_inv * STRETCH;
            int y_projection = (int) (SCREEN_HEIGHT / 2) - ry * FOV * z_inv;

            // Get the index of the projection on the screen
            int index = x_projection + y_projection * SCREEN_WIDTH;
            
            // If we're inside the range of the screen...
            if (-1 < index && index < SCREEN_HEIGHT * SCREEN_WIDTH) {
                if (z_inv > z[index]) {
                    z[index] = z_inv;
                    out[index] = illuminate(sphere, sx, sy, sz);
                }
            }
        }
    }
}