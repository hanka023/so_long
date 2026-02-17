/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/17 14:45:23 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"


int player(char **map)
{
	int	i;
	int	j;
	int p;
	
	i = 0;
	p = 0;
	while(map[i] != NULL)
	{	
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				p = 1;
			++j;
		}
		++i;
	}
	if (p == 1)
		return (1);
	else
		return (0);
}


int col(char **map)
{
	int	i;
	int	j;
	int c;
	
	i = 0;
	c = 0;
	while(map[i] != NULL)
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


int esc(char **map)
{
	int	i;
	int	j;
	int e;
	
	i = 0;
	e = 0;
	while(map[i] != NULL)
	{	
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] == 'E')
				e = 1;	
			++j;
		}
		++i;
	}
	if (e == 1)
		return (1);
	else
		return (0);
}

int player_col_esc(char **map)
{
	if (!player(map))
		return(0);
	if (!col(map))
		return(0);
	if (!esc(map))
		return(0);
	return(1);
}
