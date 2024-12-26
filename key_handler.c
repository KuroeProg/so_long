#include "so_long.h"
#include <stdio.h>

int    handle_keypress(int keycode, void *param)
{
    (void)param;

    if (keycode == 0xff1b)
    {
        printf("esc pressed\n");
        exit(0);
    }
    if (keycode == 0x0077)
    {
        printf("w printed\n");
    }

    return (0);
}

int    handle_destroy(void *param)
{
    (void)param;
    printf("destroyed\n");
    exit(0);
    return (0);
}