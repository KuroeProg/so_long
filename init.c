#include "so_long.h"

/* **************************************************************************
** This function will initialize the player structure at 0.
** **************************************************************************/
void	initialize_player(t_game *game, int start_x, int start_y)
{
	game->player_x = start_x;
	game->player_y = start_y;
	game->collected_items = 0;
	game->move_count = 0;
}