/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 01:21:48 by cfiachet          #+#    #+#             */
/*   Updated: 2024/12/30 20:22:04 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill(t_game *game, int i, int j)
{
	if (i < 0 || j < 0 || i >= game->map_width || j >= game->map_height)
		return ;
	if (game->map[j][i] == '1' || game->map[j][i] == 'F')
		return ;
	if (game->map[j][i] == '0' || game->map[j][i] == 'P' 
		|| game->map[j][i] == 'C' || game->map[j][i] == 'E')
	{
		game->map[j][i] = 'F';
		ft_flood_fill(game, i + 1, j);
		ft_flood_fill(game, i - 1, j);
		ft_flood_fill(game, i, j + 1);
		ft_flood_fill(game, i, j - 1);
	}
}
void	ft_check(t_check *check, int i, int j, t_game *game)
{
	if (check->check_exit != 1 || check->check_player != 1
		|| check->check_item < 1)
		{
			ft_error();
		}
	ft_flood_fill(game, i, j);
}

void	ft_isborder(int *i, int *j, t_game *game)
{
	while (*i < game->map_width)
	{
		if (game->map[0][*i] != '1' || game->map[game->map_height - 1][*i] != '1')
			ft_error();
		i++;
	}
	while (*j < game->map_height)
	{
		if (game->map[*j][0] != '1' || game->map[*j][game->map_width - 1] != '1')
			ft_error();
		j++;
	}
}

void    is_conform(t_game *game)
{
	int			i;
	int			j;
	t_check		check;

	j = 0;
	i = 0;
	check = (t_check){0, 0, 0};
	ft_isborder(&i, &j, game);
	while (j < game->map_height)
	{
		while (i < game->map_width)
		{
			if (game->map[j][i] == 'C')
				check.check_item++;
			if (game->map[j][i] == 'E')
				check.check_exit++;
			if (game->map[j][i] == 'P')
				check.check_player++;
			i++;
		}
		i = 0;
		j++;
	}
	ft_check(&check, game->player_start_x, game->player_start_y, game);
}