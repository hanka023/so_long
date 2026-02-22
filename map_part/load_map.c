/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/21 22:34:55 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_images(void *mlx, t_images *imgs)
{
	int	w;
	int	h;

	imgs ->floor = mlx_xpm_file_to_image(mlx, "img/floor.xpm", &w, &h);
	imgs -> wall = mlx_xpm_file_to_image(mlx, "img/wall.xpm", &w, &h);
	imgs ->player = mlx_xpm_file_to_image(mlx, "img/player.xpm", &w, &h);
	imgs ->col = mlx_xpm_file_to_image(mlx, "img/col.xpm", &w, &h);
	imgs ->exit = mlx_xpm_file_to_image(mlx, "img/exit.xpm", &w, &h);
}

void	render_map(void *mlx, void *win, char **map, t_images *imgs)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(mlx, win, imgs->wall, j * 32, i * 32);
			else if (map[i][j] == '0')
				mlx_put_image_to_window(mlx, win, imgs->floor, j * 32, i * 32);
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(mlx, win, imgs->player, j * 32, i * 32);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(mlx, win, imgs->col, j * 32, i * 32);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(mlx, win, imgs->exit, j * 32, i * 32);
			j++;
		}
		i++;
	}
	return ;
}

char	**load_map(void)
{
	char	*filename;
	char	**map;

	filename = "map/map.ber";
	map = read_map(filename);
	if (!map || !validate_map(map) || !flood_fill_main(map))
	{
		error();
		free_map(map);
		return (0);
	}
	print_map (map);
	return (map);
}
