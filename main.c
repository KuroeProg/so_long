/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:49:45 by cfiachet          #+#    #+#             */
/*   Updated: 2024/12/28 17:29:59 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int		render_frame(t_game *game)
{
	int j;

	j = 0;
	while (game->map[j])
	{
		display_line(game->map[j], game->mlx_connection, game->mlx_window, &game->img, j);
		ft_movesprite(game->map[j], game->mlx_connection, game->mlx_window, j, &game->img);
		j++;
	}
	return (0);
}

/* ********************************************************************
** The main function is here to 'pilote' the program
** It will initialize the mlx connection, the window, the sprites
** and the player. Then it will parse the map and run the game loop
** the 'mlx' functions are from the graphic library minilibx
** the 'ft_parsing' function is a custom function that will parse the map
** the 'run_game_loop' function is a custom function that will run the game loop
** at the end, it will free the memory and close the program.
** *******************************************************************/
int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf("Error\nUsage: ./so_long [map.ber]\n"), 1);
	game.mlx_connection = mlx_init();
	ft_parsing(argv[1], &game);
	game.mlx_window = mlx_new_window(game.mlx_connection, game.map_width * 32, game.map_height * 32, "so_long");
	game.img = load_sprites(game.mlx_connection);
	mlx_key_hook(game.mlx_window, handle_keypress, &game);
	mlx_loop_hook(game.mlx_connection, render_frame, &game);
	mlx_loop(game.mlx_connection);
	
	
	// Free
	return (0);
}