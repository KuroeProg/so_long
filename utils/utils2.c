/* ************************************************************************** */
/*												                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:31:18 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/02 22:31:39 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(t_game *game)
{
	free_sprites(&game->img, game->mlx_connection);
	if (game->mlx_window)
	{
		mlx_destroy_window(game->mlx_connection, game->mlx_window);
		game->mlx_window = NULL;
	}
	if (game->mlx_connection)
	{
		mlx_destroy_display(game->mlx_connection);
		free(game->mlx_connection);
		game->mlx_connection = NULL;
	}
	if (game->map)
	{
		free_map(game->map);
		game->map = NULL;
	}
}
