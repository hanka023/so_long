/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanka <hanka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/16 01:39:32 by hanka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int main(int argc, char *argv[])
{
	int fd;
	char *line;
	char *filename;
	char **map;
	int i;

	i = 0;
	(void)argc;
	(void)argv;
	filename = "map/map_ko.ber";
	fd = open(filename, O_RDONLY);
	map = read_map(filename);
	if(!validate_map(map))
		return(0);
	while ((line = get_next_line(fd)))
	{
		ft_printf("%s", line);
		free(line);
	}
	close (fd);
	while (map[i])
	{
		free(map[i]);  // uvolníme každý řádek
		i++;
	}
	free(map);
}
