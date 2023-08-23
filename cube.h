#ifndef CUBE_H_
#define CUBE_H_

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 50

#define FOV 50.0f

#define SPEED 0.15f
#define OBJECT_DISTANCE 100.0f

#define HEIGHT 20.0f
#define WIDTH 20.0f
#define DEPTH 20.0f

#define STRETCH 2

// Render a frame of the donut
void render_frame(void);

#endif