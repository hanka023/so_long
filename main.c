/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/23 16:28:12 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char		**map;
	void		*mlx;
	t_images	imgs;
	t_game		game;

	if (argc != 2)
	{
		error_msg("Wrong count of arguments!");
		return (0);
	}
	map = load_map(argv[1]);
	if (!map)
		return (0);
	mlx = mlx_init();
	game.images = &imgs;
	load_images (mlx, game.images);
	game.window.w = (ft_strlen (map[0]) - 1) * 32;
	game.window.h = count_lines (map) * 32;
	game.win = mlx_new_window(mlx, game.window.w, game.window.h, "so_long");
	load_game (&game, mlx, game.win, map);
	render_map (game.mlx, game.win, game.map, game.images);
	start_player (&game);
	mlx_key_hook (game.win, key_handler, &game);
	mlx_hook (game.win, 17, 0, close_game, &game);
	mlx_loop (game.mlx);
}
