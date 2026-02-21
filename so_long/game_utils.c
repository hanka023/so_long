/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/21 22:05:59 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	init_game (t_game *game, void *mlx, void *win, char **map, t_images *imgs)
{
	game -> mlx = mlx;
	game -> win = win;
	game -> map = map;
	game -> images = imgs;
	game -> moves = 0;
	return ;
}

void key_code(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_game(game);
	else if (keycode == 119 || keycode == 65362)
		(game -> new_y)--;
	else if (keycode == 115 || keycode == 65364)
		(game -> new_y)++;
	else if (keycode == 97 || keycode == 65361)
		(game -> new_x)--;
	else if (keycode == 100 || keycode == 65363)
		(game -> new_x)++;
	return ;
}

void player_moves(t_game *game)
{
	if (game->map[game -> new_y][game -> new_x] == '1')
		return ;
	if (game->map[game -> new_y][game -> new_x] == 'C')
		(game -> col)--;
	if (game->map[game -> new_y][game -> new_x] == 'E')
	{
		if (game -> col == 0)
		{
			ft_printf("\nYOU WIN!!!\n\n");	
			close_game(game);
		}
		else 
			return ;
	}
	++(game -> moves);
	ft_printf("Moves: %d\n",game ->moves);	
 	game->map[game->player_y][game->player_x] = '0';
	game->map[game -> new_y][game -> new_x] = 'P';
	game->player_x = game -> new_x;
	game->player_y = game -> new_y;
	return ;
}

int	key_handler(int keycode, t_game *game)
{	
	
	game -> new_x = game -> player_x;
	game -> new_y = game -> player_y;
	key_code(keycode, game);
	player_moves(game);
	render_map(game->mlx, game->win, game->map, game->images);
	return (0);
}

int	close_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->images ->floor);
	mlx_destroy_image(game->mlx, game->images -> wall);
	mlx_destroy_image(game->mlx, game->images -> player);
	mlx_destroy_image(game->mlx, game->images -> col);
	mlx_destroy_image(game->mlx, game->images -> exit);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->map);
	exit (0);
}
