#include "render.h"
#include "rotation.h"

#include "cube.h"

static float z[SCREEN_HEIGHT * SCREEN_WIDTH] = { [0 ... SCREEN_HEIGHT * SCREEN_WIDTH - 1] = 0.0f };
static char out[SCREEN_HEIGHT * SCREEN_WIDTH] = { [0 ... SCREEN_HEIGHT * SCREEN_WIDTH - 1] = ' ' };


void render() {
    // clear screen
    printf("\x1b[2J");

    cube_t *cube = (cube_t *) calloc(1, sizeof(cube_t));
    cube->width = 10;
    cube->height = 10;
    cube->depth = 10;
    cube->x = 0;
    cube->y = 0;
    cube->z = 0;

    rotation_t *cube_rot = (rotation_t *) calloc(1, sizeof(rotation_t));
    cube->rotation = cube_rot;

    cube_rot->axis = XY;
    cube_rot->rotation_speed = 0.02f;
    cube_rot->angle = 0.0f;

    cube_t *cube1 = (cube_t *) calloc(1, sizeof(cube_t));
    cube1->width = 10;
    cube1->height = 10;
    cube1->depth = 10;
    cube1->x = 20;
    cube1->y = 20;
    cube1->z = 20;

    rotation_t *cube1_rot = (rotation_t *) calloc(1, sizeof(rotation_t));
    cube1->rotation = cube1_rot;

    cube1_rot->axis = YZ;
    cube1_rot->rotation_speed = 0.05f;
    cube1_rot->angle = 0.0f;


    for (;;) {
        // reset coordinate buffer and output buffer
        memset(z, 0.0f, sizeof(z));
        memset(out, ' ', SCREEN_HEIGHT * SCREEN_WIDTH);
        
        // render
        render_cube_frame(cube, z, out);
        render_cube_frame(cube1, z, out);

        // move cursor to top left of screen and print output
        printf("\x1b[H");
        for (int i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH; i++) {
            if (i % SCREEN_WIDTH == 0) putchar('\n');
            putchar((int) out[i]);
        }
        putchar('\n');
    }
}

int main(void) {
    render(z, out);

    return 0;
}