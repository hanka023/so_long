/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/18 21:02:00 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int maps()
{
	char *filename;
	char **map;

	filename = "map/map_ko.ber";
	map = read_map(filename);
	if (!map)
	{	
		free_map(map);
		return (0);
	}
	if(!validate_map(map))
		return (0);
	ft_printf("\n puvodni mapa \n");
	print_map (map);
	ft_printf("\n\n");
	if (!flood_fill_main(map))
		return (0);
	ft_printf("\n");
	free_map(map);
	return (1);
}

int main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		width;
	int		height;

	maps();
	if (!maps())
		{
			ft_printf("Error\n");
			return (0);
		}
	mlx = mlx_init();
	if (!mlx)
		return (1);

	win = mlx_new_window(mlx, 800, 600, "so_long");
	if (!win)
		return (1);

	img = mlx_xpm_file_to_image(mlx, "img/helicopter.xpm", &width, &height);
	if (!img)
	{
		printf("IMAGE FAILED\n");
		mlx_loop(mlx);
	}

	mlx_string_put(mlx, win, 100, 100, 0xFFFFFF, "Hello");
	mlx_put_image_to_window(mlx, win, img, 100, 100);

	mlx_loop(mlx);
	return (0);
}
