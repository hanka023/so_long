/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/22 18:39:49 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include "../minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# define TILE 64

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_window
{
	int width;
	int height;
}	t_window;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_images
{
	void	*floor;
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit;
} t_images;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			player_x;
	int			player_y;
	int			new_x;
	int			new_y;
	int			moves;
	char		**map;
	int			col;
	t_images	*images;
	t_window	window;
} t_game;

/********	map_part - flood_fill	********/

void	fill(char **tab, t_point size, int row, int col);
void	flood_fill(char **tab, t_point size, t_point begin);
char	**make_area(int len, int rows, char **map);
int		zero_check(char **map);
int		flood_fill_main(char **area);

/********	map_part - load_map	********/

void	load_images(void *mlx, t_images *imgs);
void	render_map(void *mlx, void *win, char **map, t_images *imgs);
char	**load_map(void);

/********	map_part - map_utils	********/

void	free_map(char **map);
void	print_map(char **map);
int		count_lines(char **lines);
int		ft_strlen_map(char *s);
void	ft_strncpy_map(char *dest, const char *src);

/********	map_part - player_position	********/

t_point	find_player(char **map);
int		count_collectibles(char **map);
void	start_player(t_game *game);

/********	map_part - read_map	********/

void	free_lines(char **lines);
int		count_lines_filename(char *filename);
int		line_len(char *filename);
char	**read_line(char **lines, int count, int fd);
char	**read_map(char *filename);

/********	map_part - validate_map_1	********/

int		right_map(char **map);
int		walls_top_down(char **map);
int		walls_sides(char **map);
int		validate_map(char **map);

/********	map_part - validate_map_2	********/

int		player(char **map);
int		col(char **map);
int		esc(char **map);
int		player_col_esc(char **map);

/********	game_utils	********/

void	key_code(int keycode, t_game *game);
void	player_moves(t_game *game);
int		key_handler(int keycode, t_game *game);
int		close_game(t_game *game);

/********	utils	********/

void	ft_strncpy(char *dest, const char *src);
void	error();

/********	main	********/

int		main(void);

#endif
