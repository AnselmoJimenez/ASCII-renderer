#ifndef SPHERE_H_
#define SPHERE_H_

#define THETA_INCREMENT 0.01f
#define PHI_INCREMENT 0.01f

#define PI 3.141592

typedef struct {
    int r;      // radius of sphere
    int x;
    int y;
    int z;      // x, y, and z offsets
} sphere_t;

// determine the character to display based off of the lumination
char determine_lumination(sphere_t *sphere, float sx, float sy, float sz);

// Render a frame of the sphere
void render_sphere_frame(sphere_t *sphere, float *z, char *out);

#endif