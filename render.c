#include "render.h"
#include "rotation.h"

#include "sphere.h"
#include "cube.h"
#include "cylinder.h"

static float z[SCREEN_HEIGHT * SCREEN_WIDTH] = { [0 ... SCREEN_HEIGHT * SCREEN_WIDTH - 1] = 0.0f };
static char out[SCREEN_HEIGHT * SCREEN_WIDTH] = { [0 ... SCREEN_HEIGHT * SCREEN_WIDTH - 1] = ' ' };


void render() {
    // clear screen
    printf("\x1b[2J");

    cylinder_t *cylinder = (cylinder_t *) calloc(1, sizeof(cylinder_t));
    cylinder->r = 10;
    cylinder->l = 10;
    
    rotation_t *rotation = (rotation_t *) calloc(1, sizeof(rotation_t));
    rotation->axis = XY;
    rotation->rotation_speed = 0.05f;

    cylinder->rotation = rotation;
    
    for (;;) {
        // reset coordinate buffer and output buffer
        memset(z, 0.0f, sizeof(z));
        memset(out, ' ', SCREEN_HEIGHT * SCREEN_WIDTH);
        
        // render
        render_cylinder_frame(cylinder, z, out);

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