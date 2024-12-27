/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:07:50 by cfiachet          #+#    #+#             */
/*   Updated: 2024/12/27 21:51:07 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_line(char *line, void *mlx_connection, void *mlx_window, t_img *img, int j)
{
	int i;
	
	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			mlx_put_image_to_window(mlx_connection, mlx_window,
				img->img_wall, i * 32, j * 32);
		else if (line[i] == '0' || line [i] == 'C' || line[i] == 'E' || line[i] == 'P')
			mlx_put_image_to_window(mlx_connection, mlx_window,
				img->img_path, i * 32, j * 32);
		i++;
	}
}
void	ft_movesprite(char *line, void *mlx_connection, void *mlx_window, int j, t_img *img)
{
	int	i;

	i = 0;
	while(line[i])
	{
		if (line[i] == 'P')
			mlx_put_image_to_window(mlx_connection, mlx_window, img->img_player, i * 32, j * 32);
		else if (line[i] == 'C')
			mlx_put_image_to_window(mlx_connection, mlx_window, img->img_item, i * 32, j * 32);
		else if (line[i] == 'E')
			mlx_put_image_to_window(mlx_connection, mlx_window, img->img_exit, i * 32, j * 32);
		i++;
	}
}

t_img	*load_sprites(void *mlx_connection)
{
	t_img *img;
	int widght;
	int height;

	img = malloc(sizeof(t_img));
	img->img_path = mlx_xpm_file_to_image(mlx_connection, 
		"sprites_solong/grass.xpm", &widght, &height);
	img->img_wall = mlx_xpm_file_to_image(mlx_connection, 
		"sprites_solong/water.xpm", &widght, &height);
	img->img_player = mlx_xpm_file_to_image(mlx_connection,
		"sprites_solong/player.xpm", &widght, &height);
	img->img_item = mlx_xpm_file_to_image(mlx_connection,
		"sprites_solong/item.xpm", &widght, &height);
	img->img_exit = mlx_xpm_file_to_image(mlx_connection,
		"sprites_solong/exit.xpm", &widght, &height);
	return (img);
}
void	ft_parsing(char *file_path, void *mlx_connection, void *mlx_window)
{
	int fd;
	char *line;
	t_img *img;
	int j;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return ;
	img = load_sprites(mlx_connection);
	j = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		display_line(line, mlx_connection, mlx_window, img, j);
		ft_movesprite(line, mlx_connection, mlx_window, j, img);
		free(line);
		j++;
	}
	close(fd);
	free(img);
}