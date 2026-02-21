/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/21 22:23:47 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"






int main(void)
{
	char		**map;
	void		*mlx;
	void		*win;
	int			map_width;
	int			map_height;
	t_images	imgs;
	t_game		game;
	
	map = load_map();
	map_width = (ft_strlen(map[0]) -1)* 32;
	map_height = count_lines(map) * 32;
	mlx = mlx_init();
	win = mlx_new_window(mlx, map_width,map_height,"so_long");
	load_images (mlx, &imgs);
	render_map (mlx, win, map, &imgs);
	init_game (&game, mlx, win, map, &imgs);
	start_player(&game);
	mlx_key_hook(win, key_handler, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	render_map (mlx, win, map, &imgs);
	mlx_loop(mlx);
	free_map(map);
	return (0);
}
