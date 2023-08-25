#include "rotation.h"

// rotate the x coordinate around the axis specified by an angle
float rotate_x(float x, float y, float z, rotation_t *rotation) {
    float sinA = sin(rotation->angle);
    float cosA = cos(rotation->angle);

    switch (rotation->axis) {
        case NONE: return x;
        case X: return x;
        case Y: return x*cosA - z*sinA;
        case Z: return x*cosA + y*sinA;
        case XY: return x*cosA - z*sinA;
        case XZ: return x*cosA + y*sinA;
        case YZ: return -z*sinA + x*cosA*cosA + y*cosA*sinA;
        case XYZ: return x*cosA*cosA + y*cosA*sinA - z*cosA*sinA + y*cosA*sinA*sinA - x*sinA*sinA*sinA;
    }

    return x;
}

// rotate the y coordinate around the axis specified by an angle
float rotate_y(float x, float y, float z, rotation_t *rotation) {
    float sinA = sin(rotation->angle);
    float cosA = cos(rotation->angle);

    switch (rotation->axis) {
        case NONE: return y;
        case X: return y*cosA + z*sinA;
        case Y: return y;
        case Z: return y*cosA - x*sinA;
        case XY: return y*cosA + z*cosA*sinA + x*sinA*sinA;
        case XZ: return z*sinA + y*cosA*cosA - x*sinA*cosA;
        case YZ: return y*cosA - x*sinA;
        case XYZ: return z*sinA + y*cosA*cosA - x*cosA*sinA;
    }

    return y;
}

// rotate the z coordinate around the axis specified by an angle
float rotate_z(float x, float y, float z, rotation_t *rotation) {
    float sinA = sin(rotation->angle);
    float cosA = cos(rotation->angle);

    switch (rotation->axis) {
        case NONE: return z;
        case X: return z*cosA - y*sinA;
        case Y: return z*cosA + x*sinA;;
        case Z: return z;
        case XY: return -y*sinA + z*cosA*cosA + x*cosA*sinA;;
        case XZ: return z*cosA - y*cosA*sinA - x*sinA*sinA;
        case YZ: return z*cosA + x*cosA*sinA + y*sinA*sinA;
        case XYZ: return x*cosA*sinA + y*sinA*sinA + z*cosA*cosA - y*cosA*cosA*sinA + x*cosA*sinA*sinA;
    }

    return z;
}