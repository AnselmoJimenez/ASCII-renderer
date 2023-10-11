#include "render.h"

#include "cube.h"

// Preevaluate the values at the current angle
static float cosA = 0.0f, sinA = 0.0f;

// Rotate the coordinates on XYZ and put the cooresponding character
void rotate_surface(float rx, float ry, float rz, char c, float *z_buf, char *out_buf) {
    // XYZ rotations
    float x = rx*cosA*cosA + ry*cosA*sinA - rz*cosA*sinA + ry*cosA*sinA*sinA - rx*sinA*sinA*sinA;
    float y = rz*sinA + ry*cosA*cosA - rx*cosA*sinA;
    float z = rx*cosA*sinA + ry*sinA*sinA + rz*cosA*cosA - ry*cosA*cosA*sinA + rx*cosA*sinA*sinA + object_distance;

    float z_inv = 1.0f / z;

    // Project from 3D to 2D screen
    int x_projection = (int) (SCREEN_WIDTH / 2) + x * FOV * z_inv * STRETCH;
    int y_projection = (int) (SCREEN_HEIGHT / 2) - y * FOV * z_inv;

    // Get the index of the projection on the screen
    int index = x_projection + y_projection * SCREEN_WIDTH;
    
    // If we're inside the range of the screen...
    if (-1 < index && index < SCREEN_HEIGHT * SCREEN_WIDTH) {
        if (z_inv > z_buf[index]) {
            z_buf[index] = z_inv;
            out_buf[index] = c;
        }
    }
}

// render a single frame of the cube at the current angle
void render_cube_frame(cube_t *cube, float *z_buf, char *out_buf) {
    // Update the cos and sin of the angle
    cosA = cos(angle); 
    sinA = sin(angle);

    // Render the height and width of the surface
    // Y Coordinate 
    for (float cy = -cube->height; cy < cube->height; cy += COORD_INCREMENT) {
        // X Coordinate
        for (float cx = -cube->width; cx < cube->width; cx += COORD_INCREMENT) {
            // Six Surfaces at different coordinates
            rotate_surface(cx, cy, -cube->width, '|', z_buf, out_buf);   // Front face
            rotate_surface(cx, cy, cube->width, '.', z_buf, out_buf);    // Back face
            rotate_surface(-cube->width, cy, cx, '/', z_buf, out_buf);   // Left Face
            rotate_surface(cube->width, cy, cx, '\\', z_buf, out_buf);   // Right face
            rotate_surface(cx, -cube->width, cy, '%', z_buf, out_buf);   // Bottom face
            rotate_surface(cx, cube->width, cy, '=', z_buf, out_buf);    // Front face
        }
    }
}