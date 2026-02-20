/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/20 20:25:46 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void load_images(void *mlx, t_images *imgs)
{
	int w;
	int h;

	imgs ->floor = mlx_xpm_file_to_image(mlx, "img/floor.xpm", &w, &h);
	imgs-> wall = mlx_xpm_file_to_image(mlx, "img/wall.xpm", &w, &h);
	imgs->player = mlx_xpm_file_to_image(mlx, "img/player.xpm", &w, &h);
	imgs->col = mlx_xpm_file_to_image(mlx, "img/col.xpm", &w, &h);
	imgs->exit = mlx_xpm_file_to_image(mlx, "img/exit.xpm", &w, &h);
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
	exit(0);
}


int key_handler(int keycode, t_game *game)
{	int collectibles;
    int new_x = game -> player_x;
    int new_y = game -> player_y;
	//int moves = game -> moves;


	collectibles = count_collectibles(game -> map);
	
    if (keycode == 119 || keycode == 65362)        // W
        new_y--;
    else if (keycode == 115 || keycode == 65364)   // S
        new_y++;
    else if (keycode == 97 || keycode == 65361)    // A
        new_x--;
    else if (keycode == 100 || keycode == 65363)   // D
		new_x++;
	
 	if (game->map[new_y][new_x] == 'C')
        collectibles--;
	if (game->map[new_y][new_x] == '1')
        return (0);
  	if (game->map[new_y][new_x] == 'E')
	{
		if (collectibles == 0)
			close_game(game);
		else 
			return (0);
	}
	if (game->map[new_y][new_x] != '1')
	{
		++game -> moves;
		ft_printf("Moves: %d\n",game ->moves);	
	}
	if (keycode == 65307)        // W
        close_game(game);
 	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	
	render_map(game->mlx, game->win, game->map, game->images);
	return (0);
}


void error()
{
	ft_printf("Error\n");
}

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

// void init_game (void *mlx, void *win, char **map, t_images imgs)
// {
// 	t_game game;

		
// 	game.map = map;   // <--- tady přiřadíš načtenou mapu do struktury game
// 	game.mlx = mlx;   // také sem uložit mlx
// 	game.win = win;   // a okno
// 	game.images = &imgs; // obrázky
// 	game.moves = 0;
// return ;
// }


int check_map (char **map)
{
	if (!map || !validate_map(map) || !flood_fill_main(map))
	{
		error();
		return (0);
	}
	return (1);
}

int main(void)
{
	char **map;
	void *mlx;
	void *win;
	t_images imgs;
	t_game game;
	t_point start;
	char *filename;
	
	filename = "map/map.ber";
	map = read_map(filename);

	// if (!check_map(map))
	// 	return (0);
	if (!map || !validate_map(map) || !flood_fill_main(map))
	{
		error();
		free_map(map); 
		return (0);
	}
	print_map (map);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600,"so_long");
	load_images (mlx, &imgs);
	render_map (mlx, win, map, &imgs);

	//init_game (mlx, win, map, imgs);

	game.map = map;   // <--- tady přiřadíš načtenou mapu do struktury game
	game.mlx = mlx;   // také sem uložit mlx
	game.win = win;   // a okno
	game.images = &imgs; // obrázky
	game.moves = 0;

	
	start = find_player(game.map);
	game.player_x = start.x;
    game.player_y = start.y;
	ft_printf("%d\n",game.player_y) ;
	mlx_key_hook(win, key_handler, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	render_map (mlx, win, map, &imgs);
	mlx_loop(mlx);
	// free_map(map);
	return (0);
}
