/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 01:21:48 by cfiachet          #+#    #+#             */
/*   Updated: 2024/12/31 23:07:14 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill(char **map, int map_width, int map_height, int i, int j)
{
    if (i < 0 || j < 0 || i >= map_width || j >= map_height)
        return;
    if (map[j][i] == '1' || map[j][i] == 'F')
        return;
    if (map[j][i] == '0' || map[j][i] == 'P' 
        || map[j][i] == 'C' || map[j][i] == 'E')
        map[j][i] = 'F';
	else
		return;
    ft_flood_fill(map, map_width, map_height, i + 1, j);
    ft_flood_fill(map, map_width, map_height, i - 1, j);
    ft_flood_fill(map, map_width, map_height, i, j + 1);
    ft_flood_fill(map, map_width, map_height, i, j - 1);
    
}

void	ft_check(t_check *check, int i, int j, t_game *game)
{
	int k;
	int l;
	char **map_copy;

	if (check->check_exit != 1 || check->check_player != 1
		|| check->check_item < 1)
			ft_error();
	if (game->map_height == game->map_width)
		ft_error();
	map_copy = malloc(sizeof(char *) * game->map_height);
    k = 0;
    while (k < game->map_height)
    {
        map_copy[k] = malloc(sizeof(char) * game->map_width);
		l = 0;
		while (l < game->map_width)
		{
			map_copy[k][l] = game->map[k][l];
			l++;
		}
		k++;
    }
	ft_flood_fill((char **)map_copy, game->map_width, game->map_height, i, j);
	k = 0;
	while (k < game->map_height)
	{
		l = 0;
		while (l < game->map_width)
		{
			if (map_copy[k][l] == 'C' || map_copy[k][l] == 'E')
				ft_error();
			l++;
		}
		k++;
	}
	k = 0;
	while (k < game->map_height)
	{
		free (map_copy[k]);
		k++;
	}
	free (map_copy);
}

void	ft_isborder(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->map_width)
	{
		if (game->map[0][i] != '1' || game->map[game->map_height - 1][i] != '1')
			ft_error();
		i++;
	}
	j = 0;
	while (j < game->map_height)
	{
		if (game->map[j][0] != '1' || game->map[j][game->map_width - 1] != '1')
			ft_error();
		j++;
	}
}

void    is_conform(t_game *game)
{
	int			i;
	int			j;
	t_check		check;

	check = (t_check){0, 0, 0};
	is_rectangular(game);
	ft_isborder(game);
	j = 0;
	while (j < game->map_height)
	{
		i = 0;
		while (i < game->map_width)
		{
			if (game->map[j][i] == 'C')
				(check.check_item)++;
			if (game->map[j][i] == 'E')
				(check.check_exit)++;
			if (game->map[j][i] == 'P')
				(check.check_player)++;
			i++;
		}
		j++;
	}
	ft_printf("Items: %d, Exits: %d, Players: %d\n", check.check_item, check.check_exit, check.check_player);
	ft_check(&check, game->player_start_x, game->player_start_y, game);
}