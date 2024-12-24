/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:49:45 by cfiachet          #+#    #+#             */
/*   Updated: 2024/12/24 18:22:55 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <X11/keysym.h>
# include "utils/gnl_42/get_next_line.h"

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
int     handle_keypress(int keycode, void *param);
void	ft_parsing(char *file_path, void *mlx_connection, void *mlx_window, int i);

#endif