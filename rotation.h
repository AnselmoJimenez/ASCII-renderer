#ifndef ROTATION_H_
#define ROTATION_H_

#include <math.h>

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
} axis_t;

// rotation structure to track rotation information for each polygon
typedef struct {
    axis_t axis;
    float rotation_speed;
    float angle;
} rotation_t;

// rotate the x coordinate around the axis specified by an angle
float rotate_x(float x, float y, float z, rotation_t *rotation);

// rotate the y coordinate around the axis specified by an angle
float rotate_y(float x, float y, float z, rotation_t *rotation);

// rotate the z coordinate around the axis specified by an angle
float rotate_z(float x, float y, float z, rotation_t *rotation);

#endif