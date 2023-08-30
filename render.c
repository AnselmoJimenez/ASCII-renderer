#include "render.h"
#include "rotation.h"

#include "sphere.h"
#include "cube.h"
#include "cylinder.h"
#include "cone.h"

static float z[SCREEN_HEIGHT * SCREEN_WIDTH] = { [0 ... SCREEN_HEIGHT * SCREEN_WIDTH - 1] = 0.0f };
static char out[SCREEN_HEIGHT * SCREEN_WIDTH] = { [0 ... SCREEN_HEIGHT * SCREEN_WIDTH - 1] = ' ' };


void render(shape_t shape) {
    // clear screen
    printf("\x1b[2J");

    /* cube ****************************************************************/
    cube_t *cube = (cube_t *) calloc(1, sizeof(cube_t));
    cube->width = 10;
    cube->height = 10;
    cube->depth = 10;
    
    rotation_t *cube_rotation = (rotation_t *) calloc(1, sizeof(rotation_t));
    cube_rotation->axis = XYZ;
    cube_rotation->rotation_speed = 0.05f;

    cube->rotation = cube_rotation;
    /***********************************************************************/


    /* sphere **************************************************************/
    sphere_t *sphere = (sphere_t *) calloc(1, sizeof(sphere_t));
    sphere->r = 10;
    sphere->x = 25;
    sphere->y = 15;
    sphere->z = 5;
    /***********************************************************************/


    /* Cylinder ************************************************************/
    cylinder_t *cylinder = (cylinder_t *) calloc(1, sizeof(sphere_t));
    cylinder->r = 10;
    cylinder->l = 10;
    cylinder->x = -40;
    cylinder->y = -20;
    cylinder->z = 70;

    rotation_t *cylinder_rotation = (rotation_t *) calloc(1, sizeof(rotation_t));
    cylinder_rotation->axis = XY;
    cylinder_rotation->rotation_speed = 0.1f;

    cylinder->rotation = cylinder_rotation;
    /***********************************************************************/

    /* cone ****************************************************************/
    cone_t *cone = (cone_t *) calloc(1, sizeof(cone_t));
    cone->r = 10;
    cone->l = 30;
    cone->x = 30;
    cone->y = -25;
    cone->z = 50;

    rotation_t *cone_rotation = (rotation_t *) calloc(1, sizeof(rotation_t));
    cone_rotation->axis = X;
    cone_rotation->rotation_speed = 0.05f;

    cone->rotation = cone_rotation;
    /***********************************************************************/

    for (;;) {
        // reset coordinate buffer and output buffer
        memset(z, 0.0f, sizeof(z));
        memset(out, ' ', SCREEN_HEIGHT * SCREEN_WIDTH);
        
        // render
        // render_cube_frame(cube, z, out);
        // render_cone_frame(cone, z, out);
        // render_cylinder_frame(cylinder, z, out);
        // render_sphere_frame(sphere, z, out);

        // move cursor to top left of screen and print output
        printf("\x1b[H");
        for (int i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH; i++) {
            if (i % SCREEN_WIDTH == 0) putchar('\n');
            putchar((int) out[i]);
        }
        putchar('\n');
    }
}

int main(int argc, char *argv[]) {
    int opt;

    while((opt = getopt(argc, argv, ARGUMENTS)) != -1) {
        switch(opt) {
            case 's':
                printf("option: %s\n", optarg);
                break;
        }
    }

    // render(z, out);

    return 0;
}