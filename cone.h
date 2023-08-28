#ifndef CONE_H_
#define CONE_H_

// cone type to track data of each cone
typedef struct {
    int r;  // first radius
    int l;  // length of cone
    int x;
    int y; 
    int z;  // offsets
    rotation_t *rotation;
} cone_t;

// determine the character to display based off of the face being rendered
char determine_cone_char(cone_t *cone, int cz);

// Render a frame of the cone
void render_cone_frame(cone_t *cone, float *z, char *out);

#endif