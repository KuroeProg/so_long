/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:30:43 by cfiachet          #+#    #+#             */
/*   Updated: 2024/12/28 14:30:14 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* **************************************************************************
** This function will move the player on the map.
** We will check if the player can move on the next tile. (if it's a wall or not)
** If the player can move, we will update the player position.
** If the player move on an item, we will call the collect_item function.
** If the player move on the exit, we will call the check_exit function.
** **************************************************************************/
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

/* **************************************************************************
** Here we will check if the player has collected all the items when he is on the Exit tile.
** if he does, we will print a message and exit the program.
** **************************************************************************/
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

/* **************************************************************************
** This function will collect the item on the map.
** When the player 'walk'/move on the item, we will increment the item_collected.
** and we will change the map to '0' to remove the item from the map.
** After we collect the item, all we have is the floor.
** **************************************************************************/

void	collect_item(t_player player, char **map)
{
	player->item_collected++;
	map[player->y][player->x] = '0';
}
