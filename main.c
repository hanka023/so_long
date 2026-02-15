/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/15 15:40:19 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h" 

int main(int argc, char *argv[])
{
	int fd; 
	char *line;
	
	(void)argc;
	(void)argv;

	fd = open("map/map.ber", O_RDONLY);
	// if(!validate_map(map))
	// 	return(0);
	while ((line = get_next_line(fd)))
		ft_printf("%s", line);
	close (fd);
}
