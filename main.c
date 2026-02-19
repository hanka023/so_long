/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanka <hanka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/19 14:21:06 by hanka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int maps()
{
	char *filename;
	char **map;

	filename = "map/map.ber";
	map = read_map(filename);
	if (!map)
	{
		free_map(map);
		return (0);
	}
	if(!validate_map(map))
		return (0);
	ft_printf("\n puvodni mapa \n\n");
	print_map (map);
	ft_printf("\n\n");
	if (!flood_fill_main(map))
		return (0);
	ft_printf("\n");
	free_map(map);
	return (1);
}

// void image_to_map()
// {

	// void	*mlx;
	// void	*floor;
	// void	*wall;
	// void	*player;
	// void	*exit;
	// void	*col;
	// int		width;
	// int		height;
	// t_game game;
	// floor       = mlx_xpm_file_to_image(mlx, "imgs/floor.xpm", &width, &height);
	// wall        = mlx_xpm_file_to_image(mlx, "imgs/wall.xpm", &width, &height);
	// player      = mlx_xpm_file_to_image(mlx, "imgs/player.xpm", &width, &height);
	// exit    	= mlx_xpm_file_to_image(mlx, "imgs/exit.xpm", &width, &height);
	// col 		= mlx_xpm_file_to_image(mlx, "imgs/col.xpm", &width, &height);

	// game->floor = mlx_xpm_file_to_image(game->mlx, "imgs/floor.xpm",  &width, &height);
    // game->wall = mlx_xpm_file_to_image(game->mlx, "imgs/wall.xpm",  &width, &height);
    // game->player = mlx_xpm_file_to_image(game->mlx, "imgs/player.xpm",  &width, &height);
    // game->col = mlx_xpm_file_to_image(game->mlx, "imgs/col.xpm",  &width, &height);
    // game->exit = mlx_xpm_file_to_image(game->mlx, "imgs/exit.xpm", &width, &height );

	// if (!game->floor || !game->wall || !game->player
    //     || !game->col || !game->exit)
    // {
    //     ft_printf("Error loading images\n");
    //     return ;
    // }

// }


void img_to_map()
{
	void	*mlx;
	void	*floor;
	void	*wall;
	void	*player;
	void	*exit;
	void	*col;
	void	*win;
	int		width;
	int		height;


	mlx = mlx_init();

win = mlx_new_window(mlx, 800, 600, "so_long");
	if (!win)
		return ;



	floor       = mlx_xpm_file_to_image(mlx, "imgs/floor.xpm", &width, &height);
	wall        = mlx_xpm_file_to_image(mlx, "imgs/wall.xpm", &width, &height);
	player      = mlx_xpm_file_to_image(mlx, "imgs/player.xpm", &width, &height);
	exit    	= mlx_xpm_file_to_image(mlx, "imgs/exit.xpm", &width, &height);
	col 		= mlx_xpm_file_to_image(mlx, "imgs/col.xpm", &width, &height);
	if (!wall || ! floor ||!player || !exit ||!col)
	{
		printf("IMAGE FAILED\n");
		mlx_loop(mlx);
	}



	mlx_put_image_to_window(mlx, win, floor,0 , 0);
	mlx_put_image_to_window(mlx, win, wall,64 , 0);
	mlx_put_image_to_window(mlx, win, player,128 , 0);
	mlx_put_image_to_window(mlx, win, exit,192 , 0);
	mlx_put_image_to_window(mlx, win, col,256 , 0);

	// mlx_put_image_to_window(mlx, win, floor,j * 64, i * 64);
	// mlx_put_image_to_window(mlx, win, wall,j * 64, i * 64);
	// mlx_put_image_to_window(mlx, win, player,j * 64, i * 64);
	// mlx_put_image_to_window(mlx, win, exit,j * 64, i * 64);
	// mlx_put_image_to_window(mlx, win, col,j * 64, i * 64);


	mlx_loop(mlx);
	return ;
}

// int mlx_main(void)
// {

// 	void	*mlx;
// 	void	*win;
// 	void	*img;
// 	int		width;
// 	int		height;

// 	mlx = mlx_init();
// 	if (!mlx)
// 		return (0);

// 	win = mlx_new_window(mlx, 800, 600, "so_long");
// 	if (!win)
// 		return (0);

// 	wall = mlx_xpm_file_to_image(mlx, "img/wall.xpm", &width, &height);
// 	if (!wall)
// 	{
// 		printf("IMAGE FAILED\n");
// 		mlx_loop(mlx);
// 	}

// 	mlx_string_put(mlx, win, 100, 100, 0xFFFFFF, "Hello");
// 	mlx_put_image_to_window(mlx, win, img, 100, 100);

// 	mlx_loop(mlx);
// 	return (1);
// }

void error()
{
	ft_printf("Error\n");
}

int main(void)
{
	if (!maps())
	{
		error();
		return (0);
	}
	// if (!img_to_map())
	// {
	// 	error();
	// 	return (0);
	// }
	return (0);
}
