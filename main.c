/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:49:45 by cfiachet          #+#    #+#             */
/*   Updated: 2024/12/28 14:30:17 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

/* ********************************************************************
** This function will close the program in a clean way.
** It will destroy the display and free the memory.
** That's actually the best way to not have memory leaks.
** *******************************************************************/
int	close_program(void *mlx_connection)
{
	mlx_destroy_display(mlx_connection);
	free(mlx_connection);
	exit(0);

	return (0);
}

/* ********************************************************************
** This function will make the game loop, by that, we mean that it will
** make the game run until the player close the window.
** The mlx_loop_hook function will call the render_frame function, it used here
** to update the frame (if we move we have to make an other render to update the frame)
** The mlx_key_hook function will call the handle_keypress function, it used here to
** handle the keypress event. (if we press WSAD we have to move the player, ESC we have to exit, etc..)
** it words with the mlx_hook function, the 2nd argument is the event, the 3rd argument is the mask
** The mlx_hook function will call the close_program function, it used here to close the program.
** The mlx_loop function will make the program run until the player close the window.
** *******************************************************************/
void	run_game_loop(void *mlx_connection, void *mlx_window,
	t_img *sprites, char **map, t_player *player)
{
	mlx_loop_hook(mlx_connection, &render_frame, (void *)sprites);
	mlx_key_hook(mlx_window, &handle_keypress, (void *)player);
	mlx_hook(mlx_window, 2, 1L << 0, handle_keypress, NULL);
	mlx_hook(mlx_window, 17, 0, close_program, mlx_connection);
	mlx_loop(mlx_connection);
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
	void	*mlx_connection;
	void	*mlx_window;
	t_img	*sprites;
	char	**map;
	t_player	player;

	if (argc != 2)
		return (ft_printf("Error\nUsage: ./so_long [map.ber]\n"));
	mlx_connection = mlx_init();
	mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "So_long");
	sprites = load_sprites(mlx_connection);
	map = ft_parsing(argv[1], mlx_connection, mlx_window);
	initialize_player(&player, map);
	run_game_loop(mlx_connection, mlx_window, sprites, map, &player);
	
	
	// Free
	mlx_destroy_image(mlx_connection, img->img);
	free(sprites);
	mlx_destroy_window(mlx_connection, mlx_window);
	return (0);
}