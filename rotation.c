#include "rotation.h"

float angle A = 0.0f

// rotates the given coordinates by the desired axes
void rotate(float *x, float *y, float *z, rotation_t axis) {
    float cosA = cos(A);
    float sinA = sin(A);

    switch (axis) {
        case NONE: break;
        case X:
            *y = (*y)*cosA + (*z)*sinA;
            *z = (*z)*cosA - (*y)*sinA;
            break;
        case Y:
            *x = (*x)*cosA - (*z)*sinA;
            *z = (*z)*cosA + (*x)*sinA;
            break;
        case Z:
            *x = (*x)*cosA + (*y)*sinA;
            *y = (*y)*cosA - (*x)*sinA;
            break;
        case XY:
            *x = (*x)*cosA - (*z)*sinA;
            *y = (*y)*cosA + (*z)*cosA*sinA + (*x)*sinA*sinA;
            *z = -(*y)*sinA + (*z)*cosA*cosA + (*x)*cosA*sinA;
            break;
        case XZ:
            *x = (*x)*cosA + (*y)*sinA;
            *y = (*z)*sinA + (*y)*cosA*cosA - (*x)*sinA*cosA;
            *z = (*z)*cosA - (*y)*cosA*sinA - (*x)*sinA*sinA;
            break;
        case YZ:
            *x = -(*z)*sinA + (*x)*cosA*cosA + (*y)*cosA*sinA;
            *y = (*y)*cosA - (*x)*sinA;
            *z = (*z)*cosA + (*x)*cosA*sinA + (*y)*sinA*sinA;
            break;
        case XYZ:
            *x = (*x)*cosA*cosA + (*y)*cosA*sinA - (*z)*cosA*sinA + (*y)*cosA*sinA*sinA - (*x)*sinA*sinA*sinA;
            *y = (*z)*sinA + (*y)*cosA*cosA - (*x)*cosA*sinA;
            *z = (*x)*cosA*sinA + (*y)*sinA*sinA + (*z)*cosA*cosA - (*y)*cosA*cosA*sinA + (*x)*cosA*sinA*sinA;
            break;
    }

    A += SPEED;
}

// rotate the given x coordinate by angle degrees around the axis specified
void rotate_x(float *x, rotation_t axis, float angle) {
    
}

// rotate the given y coordinate by angle degrees around the axis specified
void rotate_y(float *y, rotation_t axis, float angle);

// rotate the given z coordinate by angle degrees around the axis specified
void rotate_z(float *z, rotation_t axis, float angle);