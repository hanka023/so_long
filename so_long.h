/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/17 17:13:02 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
#include <string.h>
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"

typedef struct s_point
{
	int x;
	int y;
}	t_point;

/********	main	********/

int		main(int argc, char *argv[]);

/********	utils	********/

void	free_map(char **map);
void	print_map(char **map);
int		count_lines(char **lines);
int		ft_strlen_map(char *s);
void	ft_strncpy_map(char *dest, const char *src);

/********	validate_map	********/

int		validate_map(char **map);
int		right_map(char **map);
int		walls_top_down(char **map);
int		walls_sides(char **map);

/********	validate_map_2	********/

int		player(char **map);
int		col(char **map);
int		esc(char **map);
int		player_col_esc(char **map);

/********	read_map	********/

int		count_lines_filename(char *filename);
int		line_len(char *filename);
char	**read_map(char *filename);

/********	flood_fill	********/

void	ft_strncpy(char *dest, const char *src);
void	fill(char **tab,char target, t_point size,  int row, int col);
void	flood_fill(char **tab, t_point size, t_point begin);
char	**make_area(int len, int rows, char **map);
int		flood_fill_main(char **area);

/********	player_position	********/

t_point find_player(char **map);


#endif
