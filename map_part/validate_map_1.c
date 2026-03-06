/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/23 16:30:44 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	player(char **map)
{
	int	i;
	int	j;
	int	p;

	if (!map)
		return (0);
	i = 0;
	p = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				++p;
			++j;
		}
		++i;
	}
	if (p == 1)
		return (1);
	else if (p > 1)
		return (2);
	else
		return (0);
}

int	right_map(char **map)
{
	int	i;
	int	len;
	int	len2;

	if (!map || !map[0])
		return (0);
	i = 1;
	len = ft_strlen_map(map[0]);
	if (!len)
		return (0);
	while (map[i] != NULL)
	{
		len2 = ft_strlen_map(map[i]);
		if (len2 == len)
			++i;
		else
			return (0);
	}
	return (1);
}

int	player_col_esc_0(char **map)
{
	if (!ch(map))
	{
		error_msg("Incorrect char in map!");
		return (0);
	}
	if (!player(map))
	{
		error_msg("No player!");
		return (0);
	}
	if (!col(map))
	{
		error_msg("No collectible!");
		return (0);
	}
	if (!esc(map))
	{
		error_msg("No escape!");
		return (0);
	}
	return (1);
}

int	player_col_esc_2(char **map)
{
	if (player(map) == 2)
	{
		error_msg(">1 Player!");
		return (0);
	}
	if (esc(map) == 2)
	{
		error_msg(">1 Exit!");
		return (0);
	}
	return (1);
}

int	validate_map(char **map)
{
	if (!right_map(map))
	{
		error_msg("Not correct map!");
		return (0);
	}
	if (!walls_top_down(map))
	{
		error_msg("Not walls!");
		return (0);
	}
	if (!walls_sides(map))
	{
		error_msg("Not walls!");
		return (0);
	}
	if (!player_col_esc_0(map))
		return (0);
	if (!player_col_esc_2(map))
		return (0);
	return (1);
}
