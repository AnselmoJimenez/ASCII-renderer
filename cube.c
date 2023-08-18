#include "cube.h"

void render_frame(void) {
    float z_buffer[SCREEN_HEIGHT][SCREEN_WIDTH] = { [0 ... SCREEN_HEIGHT - 1][0 ... SCREEN_WIDTH - 1] = 0.0 };
    char out_buffer[SCREEN_HEIGHT][SCREEN_WIDTH] = { [0 ... SCREEN_HEIGHT - 1][0 ... SCREEN_WIDTH - 1] = 32 };

    // render frames infinitely
    // for (;;) {
        // X coordinate
        for (float x = -WIDTH; x < WIDTH; x += 1) {
            // Y coordinate
            for (float y = -HEIGHT; y < HEIGHT; y += 1) {
                // distance from the screen
                int z = 25;
                float z_inv = 1 / z;

                // projections
                float x_projection = x * FOV * z_inv;
                float y_projection = y * FOV * z_inv;

                printf("(%f, %f) ; ", x_projection, y_projection);
                // z_buffer[index] = z_inv;
                // out_buffer[index] = '#';
            }
        }

        printf("\n\n\n\n\n");

        // print to terminal
        // for (int k = 0; k < SCREEN_HEIGHT * SCREEN_WIDTH; k++) {
        //     putchar((int) *out_buffer[k]);
        // }
    // }

}

void main(void) {

    render_frame();
}