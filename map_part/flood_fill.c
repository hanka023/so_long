/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/22 18:44:19 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill(char **tab, t_point size, int r, int c)
{
	if (r < 0 || c < 0 || r >= size.y || c >= size.x)
		return ;
	if (tab [r][c] == 'X' || tab[r][c] == '1')
		return ;
	else if (tab[r][c] == '0')
	{
		tab [r][c] = 'X';
		fill (tab, size, r -1, c);
		fill (tab, size, r +1, c);
		fill (tab, size, r, c +1);
		fill (tab, size, r, c -1);
	}
	else if (tab[r][c] == 'P' || tab[r][c] == 'C' || tab[r][c] == 'E')
	{
		fill (tab, size, r -1, c);
		fill (tab, size, r +1, c);
		fill (tab, size, r, c +1);
		fill (tab, size, r, c -1);
	}
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin.y, begin.x);
}

char	**make_area(int len, int rows, char **map)
{
	int		y;
	char	**area;

	y = 0;
	area = malloc(sizeof(char *) * (rows + 1));
	if (!area)
		return (NULL);
	while (y < rows)
	{
		area[y] = malloc(sizeof(char) * (len + 1));
		if (!area[y])
			return (NULL);
		ft_strncpy(area[y], map[y]);
		++y;
	}
	area[rows] = NULL;
	return (area);
}

int	zero_check(char **map)
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
			if (map[i][j] == '0')
				++zero;
			++j;
		}
		++i;
	}
	return (zero);
}

int	flood_fill_main(char **area)
{
	int		len;
	int		rows;
	char	**new_area;
	t_point	size;
	t_point	player_position;

	len = ft_strlen(area[0]);
	rows = count_lines(area);
	size.x = len;
	size.y = rows;
	player_position = find_player(area);
	if (player_position.x == -1 && player_position.y == -1)
		return (0);
	new_area = make_area(len, rows, area);
	flood_fill(new_area, size, player_position);
	print_map(new_area);
	if (zero_check(new_area) > 0)
	{
		free_map(new_area);
		return (0);
	}
	free_map(new_area);
	return (1);
}
