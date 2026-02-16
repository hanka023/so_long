/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/16 22:32:03 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"


void free_map(char **map)
{
    int i = 0;

    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

int main(int argc, char *argv[])
{
	char *filename;
	char **map;
	int i;

	i = 0;
	(void)argc;
	(void)argv;
	filename = "map/map.ber";
	map = read_map(filename);
	if (!map)
		return(0);
	if(!validate_map(map))
	{
		free_map(map);
		return(0);
	}
	while (map[i])
	{
		ft_printf("%s", map[i]);
		++i;
	}
	free_map(map);
	return(0);
}
