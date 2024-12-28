#include "so_long.h"

/* **************************************************************************
** This function will initialize the player structure at 0.
** **************************************************************************/
void	initialize_player(t_player *player, char **map)
{
	player->x = 0;
	player->y = 0;
	player->item_collected = 0;
	player->map = map;
}