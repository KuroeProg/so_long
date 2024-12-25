/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:49:45 by cfiachet          #+#    #+#             */
/*   Updated: 2024/12/25 22:55:05 by cfiachet         ###   ########.fr       */
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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int     main(int argc, char **argv);
int     close_program(void *mlx_connection);
void	ft_parsing(char *file_path, void *mlx_connection, void *mlx_window, int i);
void	display_line(char *line, void *mlx_connection, void *mlx_window, void *img_path, void *img_wall, int j);
int    handle_keypress(int keycode, void *param);
int     ft_sprites_manage(void *mlx);



#endif