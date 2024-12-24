/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:07:50 by cfiachet          #+#    #+#             */
/*   Updated: 2024/12/24 18:11:34 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_line(char *line, void *mlx_connection, void *mlx_window, void *img_path, void *img_wall, int j)
{
	int i;
	
	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			mlx_put_image_to_window(mlx_connection, mlx_window, img_wall, i * 32, j * 32);
		else
			mlx_put_image_to_window(mlx_connection, mlx_window, img_path, i * 32, j * 32);
		i++;
	}
}

void	ft_parsing(char *file_path, void *mlx_connection, void *mlx_window, int i)
{
	int fd;
	char *line;
	void *img_path;
	void *img_wall;
	int j;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return ;
	img_path = mlx_xpm_file_to_image(mlx_connection, 
		"sprites_solong/grass.xpm", &i, &j);
	img_wall = mlx_xpm_file_to_image(mlx_connection, 
		"sprites_solong/water.xpm", &i, &j);
		
	j = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		display_line(line, mlx_connection, mlx_window, img_path, img_wall, j);
		free(line);
		j++;
	}
	close(fd);
}