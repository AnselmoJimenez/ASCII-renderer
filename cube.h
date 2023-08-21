#ifndef CUBE_H_
#define CUBE_H_

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 44

#define FOV 50.0f

#define SPEED 0.2f
#define CAMERA_DISTANCE 100

#define HEIGHT 20.0f
#define WIDTH 20.0f
#define DEPTH 20.0f

// Render a frame of the donut
void render_frame(void);

#endif