/* ************************************************************************** */
/*                                                                          */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:49:45 by cfiachet          #+#    #+#             */
/*   Updated: 2024/12/26 15:40:59 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include "utils/gnl/get_next_line.h"

# define WIDTH 1000
# define HEIGHT 600

typedef struct s_data {
    void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
}				t_data;

typedef struct s_player
{
	int		x;
	int		y;
	int		item_collected;
	char	**map;
}				t_player;

typedef struct s_img
{
    void    *img_path;
    void	*img_wall;
	void	*img_player;
	void	*img_item;
	void	*img_exit;
}				t_img;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int     main(int argc, char **argv);
int     close_program(void *mlx_connection);
void	ft_parsing(char *file_path, void *mlx_connection, void *mlx_window);
void	display_line(char *line, void *mlx_connection, void *mlx_window, t_img *img, int j);
int     handle_keypress(int keycode, void *param);
int		ft_sprites_manage(void *mlx);
int		handle_destroy(void *param);
void	move_player(t_player *player, int direction);
int		check_exit(t_player player);
void	collect_item(t_player *player, char **map);
void	initialize_player(t_player *player, char **map);


#endif