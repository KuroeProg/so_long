/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:49:45 by cfiachet          #+#    #+#             */
/*   Updated: 2024/12/24 18:09:14 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

int	close_program(void *mlx_connection)
{
	mlx_destroy_display(mlx_connection);
	free(mlx_connection);
	exit(0);

	return (0);
}

int	main(int argc, char **argv)
{
	void	*mlx_connection;
	void	*mlx_window;
	t_data	*img;

	if (argc != 2)
	{
		printf("Error\n");
		return (0);
	}
	mlx_connection = mlx_init();
	mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "So_long");
	img = (t_data *)malloc(sizeof(t_data));
	img->img = mlx_new_image(mlx_connection, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	mlx_put_image_to_window(mlx_connection, mlx_window, img->img, 0, 0);
	ft_parsing(argv[1], mlx_connection, mlx_window, 0);
	mlx_hook(mlx_window, 2, 1L << 0, handle_keypress, NULL);
	mlx_hook(mlx_window, 17, 0, close_program, NULL);

	mlx_loop(mlx_connection);
	

	// Free
	mlx_destroy_image(mlx_connection, img->img);
	free(img);
	mlx_destroy_window(mlx_connection, mlx_window);
	return (0);
}