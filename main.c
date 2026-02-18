/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanka <hanka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/18 02:26:24 by hanka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void maps()
{
	char *filename;
	char **map;

	filename = "map/map.ber";
	map = read_map(filename);
	if (!map)
		return ;
	if(!validate_map(map))
	{
		free_map(map);
		return ;
	}
	ft_printf("\n puvodni mapa \n");
	print_map (map);
	ft_printf("\n\n");
	flood_fill_main(map);
	ft_printf("\n");
	free_map(map);
	return ;
}

// int main(void)
// {

// 	void	*mlx;
// 	void	*win;
// 	void	*img;
// 	 void    *mlx_win;
// 	int width;
// 	int height;


// 	maps();

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 800,600, "so_long");
// 	img = mlx_xpm_file_to_image(mlx, "player.xpm",&width, &height );
// 	if (!img)
// 		return (1);


// 	mlx_string_put(mlx, mlx_win, 100, 100, 0xFFFFFF, "Hello");
// 	mlx_put_image_to_window(mlx, win, img, 100, 100);
// 	mlx_loop(mlx);

// 	return(0);
// }


int main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		width;
	int		height;

	maps();

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
