#include "so_long.h"

int    handle_keypress(int keycode, void *param)
{
    (void)param;

    if (keycode == 65307)
    {
        exit(0);
    }

    return (0);
}