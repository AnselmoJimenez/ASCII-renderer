#include "cube.h"

void render_frame(void) {
    float A = 0;

    float cosA = cos(A);
    float sinA = sin(A);

    float z_buffer[SCREEN_HEIGHT * SCREEN_WIDTH] = { [0 ... SCREEN_HEIGHT * SCREEN_WIDTH - 1] = 0.0f };
    char out_buffer[SCREEN_HEIGHT * SCREEN_WIDTH] = { [0 ... SCREEN_HEIGHT * SCREEN_WIDTH - 1] = ' ' };

    for (;;) {
        // reset contents of buffers
        memset(z_buffer, 0.0f, sizeof(z_buffer));
        memset(out_buffer, ' ', sizeof(out_buffer));

        // X coordinate
        for (float x = -WIDTH; x < WIDTH; x += SPEED) {
            // Y coordinate
            for (float y = -HEIGHT; y < HEIGHT; y += SPEED) {
                // Z coordinate
                for (float z = -DEPTH; z < DEPTH; z += SPEED) {
                    float preeval = x * cosA + y * sinA;

                    // rotation calculations
                    float rx = -z * sinA + cosA * preeval;
                    float ry = y * cosA - x * sinA;
                    float rz = (z * cosA + sinA * preeval) + CAMERA_DISTANCE;
                    float z_inv = 1.0f / rz;

                    // projections
                    int x_projection = (int) (SCREEN_WIDTH / 2) + rx * FOV * z_inv;
                    int y_projection = (int) (SCREEN_HEIGHT / 2) - ry * FOV * z_inv;

                    int index = x_projection + y_projection * SCREEN_WIDTH;
                    if (z_inv > z_buffer[index]) {
                        z_buffer[index] = z_inv;
                        out_buffer[index] = '#';
                    }   
                }
            }
        }
        
        printf("\x1b[H");   // move cursor to top left
        
        // print output
        for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
            if (i % SCREEN_WIDTH == 0) putchar('\n');
            putchar((int) out_buffer[i]);
        }
        putchar('\n');

        A += 0.05;

        cosA = cos(A);
        sinA = sin(A);
    }
}

int main(void) {
    printf("\x1b[2J");  // Clear screen
    render_frame();

    return 0;
}