#include "donut.h"

void render_frame(float A, float B) {
    // Z Buffer holds coordinates of all points on the object init to 0
    // Output Buffer holds characters for the output init to ' '
    float z_buffer[SCREEN_WIDTH][SCREEN_HEIGHT] = { [0 ... SCREEN_WIDTH - 1][0 ... SCREEN_HEIGHT - 1] = 0 };
    char out_buffer[SCREEN_WIDTH][SCREEN_HEIGHT] = { [0 ... SCREEN_WIDTH - 1][0 ... SCREEN_HEIGHT - 1] = 32 };

    // Precompute the values of sines and cosines of A and B
    float cosA = cos(A);
    float sinA = sin(A);
    float cosB = cos(B);
    float sinB = sin(B);

    // Create the circle of radius R1 by sweeping an angle theta from 0 to 2pi
    for (float theta = 0; theta < 2 * PI; theta += THETA_INCREMENT) {
        // Precompute values of sin and cos of theta
        float cosTheta = cos(theta);
        float sinTheta = sin(theta);

        // Rotate that circle by an angle phi around the Y axis
        for (float phi = 0; phi < 2 * PI; phi += PHI_INCREMENT) {
            // Precompute values for sin and cos of phi
            float cosPhi = cos(phi);
            float sinPhi = sin(phi);

            // coordinates for the original circle
            float circle_x = R2 + R1 * cosTheta;
            float circle_y = R1 * sinTheta;
            float circle_z = 0;

            // Revolution coordinates
            float rev_x = circle_x * cosPhi;
            float rev_y = circle_y;
            float rev_z = -circle_x * sinPhi;

            // Final 3D coordinates
            float final_x = cosB * rev_x + sinB * (cosA * sinTheta * R1 - sinA * sinTheta * circle_x);
            float final_y = -rev_x * sinB + cosB * (cosA * sinTheta * R1 - sinA * sinTheta * circle_x);            
            float final_z = -sinA * sinTheta * R1 - cosA * sinTheta * circle_x;

            // X and Y projection onto screen
            int proj_x = (int) (SCREEN_WIDTH / 2 + K1 * (1 / final_z) * final_x);
            int proj_y = (int) (SCREEN_HEIGHT / 2 - K1 * (1 / final_z) * final_y);
        }
    }    
}

int main() { 
    
    
    return 0;
}