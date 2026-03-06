/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/23 16:32:32 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	col(char **map)
{
	int	i;
	int	j;
	int	c;

	if (!map)
		return (0);
	i = 0;
	c = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				c = 1;
			++j;
		}
		++i;
	}
	if (c == 1)
		return (1);
	else
		return (0);
}

int	esc(char **map)
{
	int	i;
	int	j;
	int	e;

	if (!map)
		return (0);
	i = 0;
	e = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] == 'E')
				++e;
			++j;
		}
		++i;
	}
	if (e == 1)
		return (1);
	else if (e > 1)
		return (2);
	else
		return (0);
}

int	ch(char **map)
{
	int	i;
	int	j;
	int	another_char;

	if (!map)
		return (0);
	i = 0;
	another_char = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] != '0' && map[i][j] != '1')
				if (map[i][j] != 'P' && map[i][j] != 'C' && map[i][j] != 'E')
					++another_char;
			++j;
		}
		++i;
	}
	if (another_char == 0)
		return (1);
	else
		return (0);
}

int	walls_top_down(char **map)
{
	int	i;
	int	j;
	int	last;

	i = 0;
	j = 0;
	last = 0;
	while (map[last] != NULL)
		++last;
	if (last < 3)
		return (0);
	last--;
	while (map[0][j] != '\n' && map[0][j] != '\0')
	{
		if (map[i][j] != '1' || map[last][j] != '1')
			return (0);
		++j;
	}
	return (1);
}

int	walls_sides(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen_map(map[0]);
	while (map[i] != NULL)
	{
		while (map[i] != NULL)
		{
			if (map[i][0] != '1')
				return (0);
			++i;
		}
	}
	i = 0;
	j = len - 1;
	while (map[i] != NULL)
	{
		if (map[i][j] != '1')
			return (0);
		++i;
	}
	return (1);
}
