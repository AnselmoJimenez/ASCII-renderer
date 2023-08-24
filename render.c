#include "render.h"
#include "cube.h"

static float z[SCREEN_HEIGHT * SCREEN_WIDTH] = { [0 ... SCREEN_HEIGHT * SCREEN_WIDTH - 1] = 0.0f };
static char out[SCREEN_HEIGHT * SCREEN_WIDTH] = { [0 ... SCREEN_HEIGHT * SCREEN_WIDTH - 1] = ' ' };


void render() {
    // clear screen
    printf("\x1b[2J");

    cube_t *cube = (cube_t *) calloc(1, sizeof(cube_t));
    cube->width = 20.0f;
    cube->height = 20.0f;
    cube->depth = 20.0f;
    cube->x = 5;
    cube->y = 5;
    cube->z = 5;

    while (true) {
        // reset coordinate buffer and output buffer
        memset(z, 0.0f, sizeof(z));
        memset(out, ' ', SCREEN_HEIGHT * SCREEN_WIDTH);
        
        // render
        render_cube_frame(cube, z, out);

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