#include "so_long.h"

int    handle_keypress(int keycode, void *param)
{
    t_player *player = (t_player *)param;
	initialize_player(player);

    if (keycode == 0xff1b)
        exit(0);
    else if (keycode == 0x0077)
		move_player(player, player->map, 0);
	else if (keycode == 0x0073)
		move_player(player, player->map, 1);
	else if (keycode == 0x0061)
		move_player(player, player->map, 2);
	else if (keycode == 0x0064)
		move_player(player, player->map, 3);
	return (0);
}

int    handle_destroy(void *param)
{
    (void)param;
    ft_printf("destroyed\n");
    exit(0);
    return (0);
}