
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanka <hanka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/15 23:21:26 by hanka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

void ft_strncpy(char *dest, const char *src)
{
	int i;
	
	if (!dest || !src)
		return;
	i = 0;
	while ((src[i] != '\0'))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return;
}


void fill(char **tab,char target, t_point size,  int row, int col)
{
	if (row < 0 || col < 0  || row >= size.y || col >= size.x)
		return;
	if ( tab [row][col] == 'X' || tab[row][col] == '1')
		return;
	else if ( tab [row][col] == '0' )
	{
	tab [row][col] = 'X';
	fill (tab, target, size, row -1, col);
	fill (tab, target, size, row +1, col);
	fill (tab, target, size, row, col +1);
	fill (tab, target, size, row, col -1);
	}
	else if ( tab [row][col] == 'P' )
	{
	fill (tab, target, size, row -1, col);
	fill (tab, target, size, row +1, col);
	fill (tab, target, size, row, col +1);
	fill (tab, target, size, row, col -1);
	}
	else if (tab [row][col] == 'C'  || tab [row][col] == 'E')
	{
	fill (tab, target, size, row -1, col);
	fill (tab, target, size, row +1, col);
	fill (tab, target, size, row, col +1);
	fill (tab, target, size, row, col -1);
	}
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	//char target = tab[begin.y][begin.x];

	char target = '0';
	// char target_p = 'P';
	// char target_e = 'E';
	// char target_c = 'C';
	fill(tab, target, size, begin.y, begin.x);
}

char **make_area(int len, int rows, char **map)
{
	int y;
	char **area;

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
    return area;
}

int flood_fill_main(char **area)
{
	int len;
	int rows;
	char **new_area;
	t_point size;
	t_point player_position;
	len = ft_strlen(area[0]);
	rows = count_lines(area);
	size.x = len;
	size.y = rows;
	player_position = find_player(area);
	if (player_position.x == -1 && player_position.y == -1)
		return (0);
	// print_map(area);
	new_area = make_area(len, rows, area);
	flood_fill(new_area, size, player_position);
	printf("\n new area \n");
	print_map(new_area);
	free_map(new_area);
	return (0);
}
