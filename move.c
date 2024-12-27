/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:30:43 by cfiachet          #+#    #+#             */
/*   Updated: 2024/12/27 22:14:54 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_player *player, int direction)
{
	int new_x = player->x;
	int new_y = player->y;

	if (direction == 0) //gaut
		new_y--;
	else if (direction == 1) //bas
		new_y++;
	else if (direction == 2) // gauche
		new_x--;
	else if (direction == 3) //droite
		new_x++;
	if (player->map[new_y][new_x] != '1')
	{
		player->x = new_x;
		player->y = new_y;
		if (player->map[new_y][new_x] == 'C')
			collect_item(player);
		else if (player->map[new_y][new_x] == 'E')
			check_exit(player);
	}
}
int		check_exit(t_player player)
{
	if (player->item_collected != TOTAL_ITEM)
	{
		ft_printf("You need to collect all item for exit !\n");
		return (0);
	}
	ft_printf("You win !\n");
	exit(0);
}

void	collect_item(t_player player, char **map)
{
	player->item_collected++;
	map[player->y][player->x] = '0';
}
