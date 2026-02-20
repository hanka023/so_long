/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanka <hanka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/20 09:32:12 by hanka            ###   ########.fr       */
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

// int key_handler(int keycode, t_game *game)
// {


//  	if (keycode == 119) // W
//         game->player_y--;
//  	else if (keycode == 122) // W
//         game->player_y++;
//  	if (keycode == 115) // W
//         game->player_x++;
//  	if (keycode == 97) // W
//         game->player_x--;


//     ft_printf("%d\n", keycode);
//   	render_map(game->mlx, game->win, game->map, game->images);

//     return (0);
// }


// int handle_key(int keycode, t_game *game)
// {
//     if (keycode == 119) // W
//         game->player_y--;
//  	else if (keycode == 122) // Z
//         game->player_y++;
//  	if (keycode == 115) // S
//         game->player_x++;
//  	if (keycode == 97) // A
//         game->player_x--;
// 	render_map(game->mlx, game->win, game->map, game->images);
//     return (0);
// }



int key_handler(int keycode, t_game *game)
{
    int new_x = game->player_x;
    int new_y = game->player_y;

    if (keycode == 119)        // W
        new_y--;
    else if (keycode == 115)   // S
        new_y++;
    else if (keycode == 97)    // A
        new_x--;
    else if (keycode == 100)   // D
        new_x++;

    // kontrola zdi
    if (game->map[new_y][new_x] == '1')
        return (0);

    // smaž starou pozici hráče
    game->map[game->player_y][game->player_x] = '0';

    // nastav novou pozici
    game->map[new_y][new_x] = 'P';

    // aktualizuj souřadnice
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



	game.map = map;   // <--- tady přiřadíš načtenou mapu do struktury game
	game.mlx = mlx;   // také sem uložit mlx
	game.win = win;   // a okno
	game.images = &imgs; // obrázky

	start = find_player(game.map);
	game.player_x = start.x;
    game.player_y = start.y;

	ft_printf("%d\n",game.player_y) ;
	// t_vars	vars;

	mlx_key_hook(win, key_handler, &game);
	//mlx_hook(game.win, 2, 1L<<0, handle_key, &game);
	render_map (mlx, win, map, &imgs);
	mlx_loop(mlx);
	free_map(map);
	return (0);
}
