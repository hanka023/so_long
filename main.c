/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/22 17:37:09 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	char		**map;
	void		*mlx;
	void		*win;
	t_images	imgs;
	t_game		game;

	map = load_map();
	mlx = mlx_init();
	game.window.width = (ft_strlen (map[0]) - 1) * 32;
	game.window.height = count_lines (map) * 32;
	win = mlx_new_window(mlx, game.window.width, game.window.height, "so_long");
	game.mlx = mlx;
	game.win = win;
	game.map = map;
	game.images = &imgs;
	game.moves = 0;
	load_images (mlx, game.images);
	render_map (game.mlx, game.win, game.map, game.images);
	start_player (&game);
	mlx_key_hook (game.win, key_handler, &game);
	mlx_hook (game.win, 17, 0, close_game, &game);
	mlx_loop (game.mlx);
	return (0);
}
