/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mapbis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 22:10:16 by cfiachet          #+#    #+#             */
/*   Updated: 2024/12/31 23:19:41 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    is_rectangular(t_game *game)
{
    int i;
    int line_length;

	if (!game->map || game->map_height == 1)
		ft_error();
    line_length = nl_strlen(game->map[0]);
	i = 1;
    while (i < game->map_height)
    {
        if (nl_strlen(game->map[i]) != line_length)
        {
            ft_printf("Erreur: la carte n'est pas rectangulaire\n");
            ft_error();
        }
        i++;
    }
    game->map_width = line_length;
}