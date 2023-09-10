#include "render.h"

#include "pyramid.h"

static float cosA = 0.0f, sinA = 0.0f;

// determine the character for the pyramid face
char rotate_plane(float cx, float cy, float cz, char c, float *z, char *out) {
    // XYZ rotations
    float rx = cx*cosA*cosA + cy*cosA*sinA - cz*cosA*sinA + cy*cosA*sinA*sinA - cx*sinA*sinA*sinA;
    float ry = cz*sinA + cy*cosA*cosA - cx*cosA*sinA;
    float rz = cx*cosA*sinA + cy*sinA*sinA + cz*cosA*cosA - cy*cosA*cosA*sinA + cx*cosA*sinA*sinA + OBJECT_DISTANCE;

    float z_inv = 1.0f / rz;
        
    // projections
    int x_projection = (int) (SCREEN_WIDTH / 2) + rx * FOV * z_inv * STRETCH;
    int y_projection = (int) (SCREEN_HEIGHT / 2) - ry * FOV * z_inv;

    // Ge>t the index of the projection on the screen
    int index = x_projection + y_projection * SCREEN_WIDTH;
    
    // If we're inside the range of the screen...
    if (-1 < index && index < SCREEN_HEIGHT * SCREEN_WIDTH) {
        if (z_inv > z[index]) {
            z[index] = z_inv;
            out[index] = c;
        }
    }

    return 0;
}

// draw one layer of the pyramid
void draw_base(pyramid_t *pyramid, float height, float width, float cz, float *z, char *out) {
    // Y Coordinate
    for (float cy = -height; cy < height; cy += COORD_INCREMENT) {
        // X Coordinate
        for (float cx = -width; cx < width; cx += COORD_INCREMENT) {
            rotate_plane(cx, cy, -pyramid->depth, '%', z, out); // Base Plane
            rotate_plane(cx, -height, cz, '/', z, out);  // right face 
            rotate_plane(cx, height, cz, '\\', z, out);  // left face
            rotate_plane(-width, cy, cz, '|', z, out);   // front face 
            rotate_plane(width, cy, cz, ':', z, out);    // back face
        }
    }
}

// render a frame of the pyramid
void render_pyramid_frame(pyramid_t *pyramid, float *z, char *out) {
    // preevaluate sin and cos of the angles
    cosA = cos(angle);
    sinA = sin(angle);

    // Trackers for height, width, and depth as we iterate through
    float depth = 2 * pyramid->depth;
    float height = pyramid->height;
    float width = pyramid->width;

    // Z Coordinate of the base
    for (float cz = -pyramid->depth; cz < pyramid->depth; cz += COORD_INCREMENT) {
        draw_base(pyramid, height, width, cz, z, out);

        depth -= COORD_INCREMENT;
        height = (pyramid->height * depth) / (2 * pyramid->depth);
        width = (pyramid->width * depth) / (2 * pyramid->depth);
    }
}