#ifndef RENDER_H_
#define RENDER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <ctype.h>
#include <ncurses.h>

#define SCREEN_WIDTH 256
#define SCREEN_HEIGHT 64

#define FOV 100.0f

#define OBJECT_DISTANCE 25.0f
#define STRETCH 2

#define COORD_INCREMENT 0.1f
#define ANGLE_INCREMENT 0.01f

#define ROTATION_SPEED 0.01f;

#define PI 3.141592

#define ARGUMENTS "hs:i:"
#define USAGE                                   \
    "USAGE: render [-h] [-s shape] \n"          \
    "\n"                                        \
    "where:\n"                                  \
    "   -h  -  help (display this message)\n"   \
    "   -s [shape]  -  renders shape\n"         \
    "      shape options: cube\n"               \
    "                     sphere\n"             \
    "                     cone\n"               \
    "                     cylinder\n"           \
    "\n"                                        \

extern float angle;
extern float object_distance;

typedef enum {
    CUBE,
    SPHERE,
    CONE,
    CYLINDER,
    PYRAMID,
} shape_t;

// Render a shape
void render(shape_t shape);

// Translate the shape entered in terminal to enum type
shape_t enumify(const char *shape);

#endif