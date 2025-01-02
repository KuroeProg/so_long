/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:07:50 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/02 14:27:12 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* ********************************************************************
** This function will display the line of the map. By 'Line' we mean
** the horizontal line of the map. We loop until the end of the line.
** If we find a '1' we put the wall sprite, if we find a '0' we put the path sprite.
** We use the mlx_put_image_to_window function to put the sprites on the window.
** *******************************************************************/

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

/* ********************************************************************
** This function will put the player, the item and the exit on the map.
** We loop until the end of the line. if we find a 'P' we put the player
** if we find a 'C' we put the item, if we find a 'E' we put the exit.
** We use the mlx_put_image_to_window function to put the sprites on the window.
** *******************************************************************/
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

/* ********************************************************************
** load_sprites function will load the sprites from the xpm files.
** We use the mlx_xpm_file_to_image function to load the sprites.
** The variables widght and height will be used to store the size of the sprites.
** We return the img structure with the sprites loaded.
** *******************************************************************/
t_img	load_sprites(void *mlx_connection)
{
    t_img img;
    int width;
    int height;

    initialize_img(&img);
    img.img_path = mlx_xpm_file_to_image(mlx_connection, 
        "sprites_solong/grass.xpm", &width, &height);
    if (!img.img_path)
        return (free_sprites(&img, mlx_connection), img);
    img.img_wall = mlx_xpm_file_to_image(mlx_connection, 
        "sprites_solong/water.xpm", &width, &height);
    if (!img.img_wall)
        return (free_sprites(&img, mlx_connection), img);
    img.img_player = mlx_xpm_file_to_image(mlx_connection,
        "sprites_solong/player.xpm", &width, &height);
    if (!img.img_player)
        return (free_sprites(&img, mlx_connection), img);
    img.img_item = mlx_xpm_file_to_image(mlx_connection,
        "sprites_solong/item.xpm", &width, &height);
    if (!img.img_item)
        return (free_sprites(&img, mlx_connection), img);
    img.img_exit = mlx_xpm_file_to_image(mlx_connection,
        "sprites_solong/exit.xpm", &width, &height);
    if (!img.img_exit)
        return (free_sprites(&img, mlx_connection), img);
    return (img);
}

void	ft_parsing(char *file_path, t_game *game)
{
    int fd;
    char *line;
    int j;
    int i;

    fd = open(file_path, O_RDONLY);
    if (fd < 0)
        return ;
    game->img = load_sprites(game->mlx_connection);
    if (!game->img.img_path || !game->img.img_wall || !game->img.img_player || !game->img.img_item || !game->img.img_exit)
    {
        free_sprites(&game->img, game->mlx_connection);
        close(fd);
        return ;
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        game->map_height++;
        free(line);
    }
    close(fd);
    game->map = malloc(sizeof(char *) * (game->map_height + 1));
    fd = open(file_path, O_RDONLY);
    if (fd < 0)
    {
        free(game->map);
        free_sprites(&game->img, game->mlx_connection);
        return ;
    }
    j = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        if (game->map_width == 0)
            game->map_width = ftff_strlen(line) - 1;
        game->map[j] = line;
        i = 0;
        while (line[i])
        {
            if (line[i] == 'P')
            {
                game->player_start_x = i;
                game->player_start_y = j;
            }
            else if (line[i] == 'C')
                game->total_items++;
            i++;
        }
        j++;
    }
    free(line);
    game->map[j] = NULL;
    close(fd);
}

/* ********************************************************************
** This function will parse the map and display it, by 'parsing' we mean that
** it will read the file and display the map depends of what is written, in the window.
** We check if the fd is valid, if not we return. (fd is the file descriptor)
** We load the sprites with the load_sprites function.
** We loop until the end of the file, we read the line and display it with the display_line function.
** We use the move_sprite function to put the player, the item and the exit. on the map.
** We free the line and close the file. And also free the img, for not having leaks.
** *******************************************************************/