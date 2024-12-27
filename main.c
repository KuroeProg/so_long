/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:49:45 by cfiachet          #+#    #+#             */
/*   Updated: 2024/12/27 22:31:25 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	close_program(void *mlx_connection)
{
	mlx_destroy_display(mlx_connection);
	free(mlx_connection);
	exit(0);

	return (0);
}

void	run_game_loop(void *mlx_connection, void *mlx_window)
{
	mlx_hook(mlx_window, 2, 1L << 0, handle_keypress, NULL);
	mlx_hook(mlx_window, 17, 0, close_program, mlx_connection);
	mlx_loop(mlx_connection);
}

int	main(int argc, char **argv)
{
	void	*mlx_connection;
	void	*mlx_window;
	t_data	*img;
	char	**map;
	t_player	player;

	if (argc != 2)
		return (ft_printf("Error\nUsage: ./so_long [map.ber]\n"));
	mlx_connection = mlx_init();
	mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "So_long");
	img = (t_data *)malloc(sizeof(t_data));
	img->img = mlx_new_image(mlx_connection, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	mlx_put_image_to_window(mlx_connection, mlx_window, img->img, 0, 0);
	map = ft_parsing(argv[1], mlx_connection, mlx_window);
	initialize_player(&player, map);
	run_game_loop(mlx_connection, mlx_window);
	
	
	// Free
	mlx_destroy_image(mlx_connection, img->img);
	free(img);
	mlx_destroy_window(mlx_connection, mlx_window);
	return (0);
}