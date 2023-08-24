#ifndef ROTATION_H_
#define ROTATION_H_

#include <math.h>

#define SPEED 0.02f

// Rotation type to decide how to rotate coordinates
typedef enum {
    NONE,
    X,
    Y, 
    Z,
    XY,
    XZ,
    YZ,
    XYZ,
} rotation_t;

// rotate the given x coordinate by angle degrees around the axis specified
void rotate_x(float *x, rotation_t axis, float angle);

// rotate the given y coordinate by angle degrees around the axis specified
void rotate_y(float *y, rotation_t axis, float angle);

// rotate the given z coordinate by angle degrees around the axis specified
void rotate_z(float *z, rotation_t axis, float angle);

#endif