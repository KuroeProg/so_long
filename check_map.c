/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 01:21:48 by cfiachet          #+#    #+#             */
/*   Updated: 2024/12/30 01:30:00 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(void)
{
	ft_printf("Error\nInvalid map\n");
	exit(1);
}

void	ft_check(t_check *check, int i, int j)
{
	if (j > i)
		ft_error();
	if (check->check_exit != 1 || check->check_player != 1
		|| check->check_item < 1)
		{
			ft_error();
		}
	// fonction flood fill pour check si la map est possible
}

void    is_conform(int fd, t_game *game, t_check *check)
{
	char	**line;
	int		i;
	int		j;

	j = 0;
	i = 0;
	line = NULL;
	while (get_next_line(fd) != NULL)
	{
		while (line[j][i])
		{
			if (line[0][i] != '1' || line[j][0] != '1')
				ft_error();	
			if (line[weidth][i] != '1' || line[j][height] != '1')
			// check if the map is surrounded by walls
				ft_error();
			if (line[j][i] == 'C')
				check->check_item++;
			if (line[j][i] == 'E')
				check->check_exit++;
			if (line[j][i] == 'P')
				check->check_player++;
			i++;
		}
		j++;
	}
	ft_check(check, i , j);
}