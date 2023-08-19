#include "cube.h"

void render_frame(void) {
    float z_buffer[SCREEN_HEIGHT][SCREEN_WIDTH] = { [0 ... SCREEN_HEIGHT - 1][0 ... SCREEN_WIDTH - 1] = 0.0f };
    char out_buffer[SCREEN_HEIGHT][SCREEN_WIDTH] = { [0 ... SCREEN_HEIGHT - 1][0 ... SCREEN_WIDTH - 1] = ' ' };

    // X coordinate
    for (float x = -WIDTH; x < WIDTH; x += 0.05) {
        // Y coordinate
        for (float y = -HEIGHT; y < HEIGHT + 1; y += 0.05) {
            // distance from the screen
            float z = 30.0f;
            float z_inv = 1.0f / z;

            // projections
            int x_projection = (int) (SCREEN_WIDTH / 2) + x * FOV * z_inv;
            int y_projection = (int) (SCREEN_HEIGHT / 2) - y * FOV * z_inv;


            out_buffer[y_projection][x_projection] = '#';
        }
    }

    // print output
    for (int j = 0; j < SCREEN_HEIGHT; j++) {
        for (int i = 0; i < SCREEN_WIDTH; i++) {
            printf("%c", out_buffer[i][j]);
        }
        printf("\n");
    }

}

int main(void) {
    render_frame();

    return 0;
}