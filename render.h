#ifndef RENDER_H_
#define RENDER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <ctype.h>

#define SCREEN_WIDTH 256
#define SCREEN_HEIGHT 64

#define FOV 100.0f

#define OBJECT_DISTANCE 25.0f
#define STRETCH 2

#define COORD_INCREMENT 0.1f
#define ANGLE_INCREMENT 0.05f

#define PI 3.141592

#define ARGUMENTS "hs:"
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

typedef enum {
    CUBE,
    SPHERE,
    CONE,
    CYLINDER,
    PYRAMID,
} shape_t;

#endif