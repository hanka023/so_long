/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/19 20:59:49 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

// int maps()
// {
// 	char *filename;
// 	char **map;

// 	filename = "map/map.ber";
// 	map = read_map(filename);
// 	if (!map)
// 	{
// 		free_map(map);
// 		return (0);
// 	}
// 	if(!validate_map(map))
// 		return (0);
// 	print_map (map);
// 	ft_printf("\n\n");
// 	if (!flood_fill_main(map))
// 		return (0);
// 	ft_printf("\n");

	
// 	free_map(map);
// 	return (1);
// }

void load_images(void *mlx, t_images *imgs)
{
	int w;
	int h;

	imgs ->floor = mlx_xpm_file_to_image(mlx, "img/floor.xpm", &w, &h);
	imgs-> wall = mlx_xpm_file_to_image(mlx, "img/floor.xpm", &w, &h);
	imgs->player = mlx_xpm_file_to_image(mlx, "img/player.xpm", &w, &h);
	imgs->col = mlx_xpm_file_to_image(mlx, "img/col.xpm", &w, &h);
	imgs->exit = mlx_xpm_file_to_image(mlx, "img/floor.xpm", &w, &h);
}


void render_map(void *mlx, void *win, char **map, t_images *imgs)
{
    int i;
	int j;

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
			{
				mlx_put_image_to_window(mlx, win, imgs->floor, j * 32, i * 32);
                mlx_put_image_to_window(mlx, win, imgs->player, j * 32, i * 32);
			}
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


int img_to_map()
{
	void	*mlx;
	void	*floor;
	//void	*wall;
	void	*player;
	//void	*exit;
	void	*col;
	void	*win;
	int		width;
	int		height;


	mlx = mlx_init();

win = mlx_new_window(mlx, 800, 600, "so_long");
	if (!win)
		return (0);

	floor       = mlx_xpm_file_to_image(mlx, "img/floor.xpm", &width, &height);
	//wall        = mlx_xpm_file_to_image(mlx, "img/wall.xpm", &width, &height);
	player      = mlx_xpm_file_to_image(mlx, "img/player.xpm", &width, &height);
	//exit    	= mlx_xpm_file_to_image(mlx, "img/exit.xpm", &width, &height);
	col 		= mlx_xpm_file_to_image(mlx, "img/col.xpm", &width, &height);
	// if (!wall || ! floor ||!player || !exit ||!col)
	// {
	// 	printf("wall FAILED\n");
	// 	mlx_loop(mlx);
	// }
	 if (!floor)
	{
		printf("floor FAILED\n");
		mlx_loop(mlx);
	}
	// if (!wall)
	// {
	// 	printf("wall FAILED\n");
	// 	//mlx_loop(mlx);
	// }
	if (!player)
	{
		printf("player FAILED\n");
		mlx_loop(mlx);
	}
	//  if (!exit)
	// {
	// 	printf("exit FAILED\n");
	// 	mlx_loop(mlx);
	// }

	mlx_put_image_to_window(mlx, win, floor,0 , 0);
	//mlx_put_image_to_window(mlx, win, wall ,256 , 64);
	mlx_put_image_to_window(mlx, win, player,64 , 0);
//	mlx_put_image_to_window(mlx, win, exit,384 , 0);
	mlx_put_image_to_window(mlx, win, col,128 , 0);

	// mlx_put_image_to_window(mlx, win, floor,j * 64, i * 64);
	// mlx_put_image_to_window(mlx, win, wall,j * 64, i * 64);
	// mlx_put_image_to_window(mlx, win, player,j * 64, i * 64);
	// mlx_put_image_to_window(mlx, win, exit,j * 64, i * 64);
	// mlx_put_image_to_window(mlx, win, col,j * 64, i * 64);

	mlx_loop(mlx);
	return (1);
}

void error()
{
	ft_printf("Error\n");
}

int main(void)
{
	char **map;
	void *mlx;
	void *win;
	t_images imgs;
	char *filename;
	
	filename = "map/map.ber";
	map = read_map(filename);
	print_map (map);
	if (!map || !validate_map(map) || !flood_fill_main(map))
	{
		error();
		return (0);
	}
	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600,"so_long");
	load_images (mlx, &imgs);
	render_map (mlx, win, map, &imgs);
	mlx_loop(mlx);
	free_map(map);
	return (0);
}
