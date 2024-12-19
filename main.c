/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:49:45 by cfiachet          #+#    #+#             */
/*   Updated: 2024/12/19 22:53:27 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
    void	*mlx_connection;
    void	*mlx_window;
    t_data	*img;

    mlx_connection = mlx_init();
    mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "So_long");
    img = (t_data *)malloc(sizeof(t_data));
    img->img = mlx_new_image(mlx_connection, WIDTH, HEIGHT);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
            &img->line_length, &img->endian);
    my_mlx_pixel_put(img, 100, 100, 0x00FF0000);
    mlx_put_image_to_window(mlx_connection, mlx_window, img->img, 0, 0);
    mlx_loop(mlx_connection);
    mlx_destroy_image(mlx_connection, img->img);
    free(img);
    mlx_destroy_window(mlx_connection, mlx_window);
    mlx_destroy_display(mlx_connection);
    free(mlx_connection);
    return (0);
}