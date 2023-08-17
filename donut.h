#ifndef DONUT_H_
#define DONUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SCREEN_WIDTH 1048
#define SCREEN_HEIGHT 1048

#define R1 1
#define R2 2
#define K2 5
#define K1 SCREEN_WIDTH * K2 * 3 / (8 * (R1 + R2))

#define THETA_INCREMENT 0.05
#define PHI_INCREMENT 0.05

#define PI 3.14159265358979323846

// Render a frame of the donut
void render_frame(float A, float B);

#endif