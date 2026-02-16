
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanka <hanka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/15 23:21:26 by hanka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"


void fill(char **tab,char target, t_point size,  int row, int col)
{
	if (row <0 || col < 0  || row >= size.y || col >= size.x)
		return;

	if ( tab [row][col] == 'F' || tab[row][col] != target)
		return;

	//else if (tab [row][col] == target)
	tab [row][col] = 'F';

	fill (tab, target, size, row -1, col);
	fill (tab, target, size, row +1, col);
	fill (tab, target, size, row, col +1);
	fill (tab, target, size, row, col -1);

}
void  flood_fill(char **tab, t_point size, t_point begin)
{
	char target = tab[begin.y][begin.x];
	fill(tab, target, size, begin.y, begin.x);
}



char **make_area(char **zone)
{
    int rows = 5; // víme, že máme 5 řádků (můžeš to parametrizovat)
    int cols = strlen(zone[0]); // délka prvního řádku
    char **area = malloc(sizeof(char *) * rows);

    for (int y = 0; y < rows; y++)
    {
        area[y] = malloc(sizeof(char) * (cols + 1)); // +1 pro '\0'
        strcpy(area[y], zone[y]);
    }

    return area;
}


void print_tab(char **tab)
{
    for (int y = 0; y < 5; y++) // 5 řádků
    {
        printf("%s\n", tab[y]);
    }
}


int flood_fill_main(void)
{
	char **area;
	t_point size = {8, 5};
	t_point begin = {2, 2};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};
	area = make_area(zone);
	print_tab(area);
	flood_fill(area, size, begin);
	//putc('\n');
	printf("\n");
	print_tab(area);
	return (0);
}
