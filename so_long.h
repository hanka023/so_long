/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanka <hanka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/15 23:30:40 by hanka            ###   ########.fr       */
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


/********	validation_map	********/


int		validate_map(char **map);
int		right_map(char **map);
int		walls_top_down(char **map);
int		walls_sides(char **map);


/********	read_map	********/


int		count_lines(char *filename);
int		line_len(char *filename);
char	**read_map(char *filename);


/********	flood_fill	********/

void	fill(char **tab,char target, t_point size,  int row, int col);
void	flood_fill(char **tab, t_point size, t_point begin);
char	**make_area(char **zone);
void	print_tab(char **tab);
int		flood_fill_main(void);


#endif
