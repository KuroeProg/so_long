#include "so_long.h"

void	initialize_player(t_player *player, char **map)
{
	player->x = 0;
	player->y = 0;
	player->item_collected = 0;
	player->map = map;
}