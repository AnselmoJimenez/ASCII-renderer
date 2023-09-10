#ifndef PYRAMID_H_
#define PYRAMID_H_

// pyramid structure to track pyramid information
typedef struct {
    float height;   // height of the pyramid
    float width;    // width of the pyramid
    float depth;        // length of the pyramid
} pyramid_t;

// render a frame of the pyramid
void render_pyramid_frame(pyramid_t *pyramid, float *z, char *out);

#endif