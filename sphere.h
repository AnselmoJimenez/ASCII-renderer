#ifndef SPHERE_H_
#define SPHERE_H_

#define THETA_INCREMENT 0.02f
#define PHI_INCREMENT 0.02f

typedef struct {
    int r;      // radius of sphere
} sphere_t;

// determine the character to display based off of the lumination
char illuminate(sphere_t *sphere, float sx, float sy, float sz);

// Render a frame of the sphere
void render_sphere_frame(sphere_t *sphere, float *z, char *out);

#endif