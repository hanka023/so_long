/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/23 18:24:25 by haskalov         ###   ########.fr       */
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

char	check_name(char *f)
{
	int	len;
	int	s;
	int	z;

	if (!f)
		return (0);
	len = ft_strlen(f);
	if (len <= 4)
		return (0);
	s = len - 4;
	z = len - 5;
	if (f[z] == '/' || f[z] == ' ' || f[z] == '\t')
		return (0);
	if (f[s] == '.' && f[s + 1] == 'b' && f[s + 2] == 'e' && f[s + 3] == 'r')
		return (1);
	return (0);
}

char	**load_map(char *filename)
{
	char	**map;

	if (!check_name (filename))
	{
		error_msg("Not possible to read map!");
		return (NULL);
	}
	map = read_map(filename);
	if (!map)
	{
		error_msg("No valid map!");
		return (NULL);
	}
	if (!validate_map(map))
	{
		free_map(map);
		return (NULL);
	}
	if (!flood_fill_main(map))
	{
		error_msg("Flood_fill fail!");
		free_map(map);
		return (NULL);
	}
	return (map);
}
