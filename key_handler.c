#include "so_long.h"

/* **************************************************************************
** This function will take the keycode and the player structure as parameter.
** We will initialize the player structure.
** If the keycode is ESC we will exit the program.
** the function is actually not linked with move.c, but it will be used in the main.c
** **************************************************************************/
int    handle_keypress(int keycode, void *param)
{
    t_game *game = (t_game *)param;
	int move;

	move = 0;
    if (keycode == 0xff1b)
        exit(0);
    else if (keycode == 0x0077)
		move = move_player(game, 0);
	else if (keycode == 0x0073)
		move = move_player(game, 1);
	else if (keycode == 0x0061)
		move = move_player(game, 2);
	else if (keycode == 0x0064)
		move = move_player(game, 3);
	if (move)
	{
		game->move_count++;
		ft_printf("Move count: %d\n", game->move_count);
	}
	return (0);
}

/* **************************************************************************
** This function will destroy the program.
** It will print a message and exit the program.
** **************************************************************************/
int    handle_destroy(void *param)
{
    (void)param;
    ft_printf("destroyed\n");
    exit(0);
    return (0);
}