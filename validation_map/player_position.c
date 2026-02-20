/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanka <hanka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/20 11:33:30 by hanka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"


t_point find_player(char **map)
{
	int	i;
	int	j;
	t_point pos;

	i = 0;
	while(map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
			{
				pos.x = j;
				pos.y = i;
				return (pos);
			}
			++j;
		}
		++i;
	}
	return ((t_point){-1, -1});
}



int count_collectibles(char **map)
{
	int	i;
	int	j;
	int c;

	if (!map)
    	return (0);
	i = 0;
	c = 0;
	while(map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				c++;
			++j;
		}
		++i;
	}
	return (c);
}
