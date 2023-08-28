#include "render.h"
#include "rotation.h"

#include "sphere.h"
#include "cube.h"
#include "cylinder.h"
#include "cone.h"

static float z[SCREEN_HEIGHT * SCREEN_WIDTH] = { [0 ... SCREEN_HEIGHT * SCREEN_WIDTH - 1] = 0.0f };
static char out[SCREEN_HEIGHT * SCREEN_WIDTH] = { [0 ... SCREEN_HEIGHT * SCREEN_WIDTH - 1] = ' ' };


void render() {
    // clear screen
    printf("\x1b[2J");

    cone_t *cone = (cone_t *) calloc(1, sizeof(cone_t));
    cone->r = 10;
    cone->l = 30;
    
    rotation_t *rotation = (rotation_t *) calloc(1, sizeof(rotation_t));
    rotation->axis = XY;
    rotation->rotation_speed = 0.05f;

    cone->rotation = rotation;
    
    for (;;) {
        // reset coordinate buffer and output buffer
        memset(z, 0.0f, sizeof(z));
        memset(out, ' ', SCREEN_HEIGHT * SCREEN_WIDTH);
        
        // render
        render_cone_frame(cone, z, out);

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