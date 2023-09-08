#ifndef PYRAMID_H_
#define PYRAMID_H_

// pyramid structure to track pyramid information
typedef struct {
    float b;    // base of the pyramid
    float l;    // length of the pyramid
} pyramid_t;

// determine the character for the pyramid face
char determine_pyramid_char(pyramid_t *pyramid, float cx, float cy, float cz);

// render a frame of the pyramid
void render_pyramid_frame(pyramid_t *pyramid, float *z, char *out);

#endif