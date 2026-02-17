/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/17 14:46:03 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

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

int	walls_top_down(char **map)
{
	int	i;
	int	j;
	int last;

	i = 0;
	j = 0;
	last = 0;
	while (map[last] != NULL)
		++last;
	if (last < 3)
		return (0);
	while(map[i][j] && map[last][j])
	{
		if (map[i][j] != 1 || map[last][j] != 1)
			return(0);
		++j;
	}
	return (1);
}

int	walls_sides(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(map[i] != NULL)
	{
		if (map[i][j] != '1')
			return(0);
		++i;
	}
	i = 0;
	j = ft_strlen_map(map[1]) - 1;
	while(map[i] != NULL)
	{
		if (map[i][j] != '1')
			return(0);
		++i;
	}
	return (1);
}

int validate_map(char **map)
{
	if (!right_map(map))
		return(0);
	if (!walls_sides(map))
		return(0);
	if (!player_col_esc(map))
		return (0);
	return(1);
}
