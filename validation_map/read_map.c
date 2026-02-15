/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/15 18:10:21 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h" 


int count_lines(char *filename)
{
	int fd;
	char *line;
	int lines;
	
	lines = 0;
	fd = open(filename, O_RDONLY);
	while ((line = get_next_line(fd)))
		++lines;
	return(lines);
}

int line_len(char *filename)
{
	int fd;
	int len;
	char *line;
	
	len = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line[len] != '\n' && line[len] != '\0')
		++len;
	close(fd);
	return(len);
}


char **read_map(char *filename)
{
	int count;
	char **lines;
	int i;
	char *line;
	int len;
	
	i = 0;
	len = line_len(filename);
	count = count_lines(filename);
	lines = malloc (sizeof (char *) * (count + 1));
	if (! lines)
		return (NULL);
		
	while (i < len)
	{
		lines[i] = malloc(sizeof(char) * len + 1);
		++i;
	}
	
 


	
	return (lines);
}