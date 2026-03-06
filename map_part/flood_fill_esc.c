/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_esc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/23 15:35:17 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill_esc(char **tab, t_point size, int r, int c)
{
	if (r < 0 || c < 0 || r >= size.y || c >= size.x)
		return ;
	if (tab[r][c] == '1' || tab[r][c] == '.')
		return ;
	else if (tab[r][c] == '0' || tab [r][c] == 'X' || tab[r][c] == 'E')
	{
		tab [r][c] = '.';
		fill_esc (tab, size, r -1, c);
		fill_esc (tab, size, r +1, c);
		fill_esc (tab, size, r, c +1);
		fill_esc (tab, size, r, c -1);
	}
	else if (tab[r][c] == 'P')
	{
		fill_esc (tab, size, r -1, c);
		fill_esc (tab, size, r +1, c);
		fill_esc (tab, size, r, c +1);
		fill_esc (tab, size, r, c -1);
	}
}

void	flood_fill_esc(char **tab, t_point size, t_point begin)
{
	fill_esc(tab, size, begin.y, begin.x);
}

int	esc_check(char **map)
{
	int	i;
	int	j;
	int	zero;

	if (!map)
		return (0);
	i = 0;
	zero = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] == 'E')
				++zero;
			++j;
		}
		++i;
	}
	return (zero);
}
