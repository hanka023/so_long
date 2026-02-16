/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanka <hanka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/16 09:36:44 by hanka            ###   ########.fr       */
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
	free(line);
	return(lines);
}

int line_len(char *filename)
{
	int fd;
	int len;
	char *line;

	len = 0;
	line = NULL;
	fd = open(filename, O_RDONLY);
	if(fd < 0)
		return(0);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (0);
	}
	len = ft_strlen(line);
	free(line);
	close(fd);
	return(len);
}


char **read_map(char *filename)
{

	int		i;
	int		fd;
	int		count;
	char	**lines;
	char	*line;
	// int		len;

	i = 0;
	// len = line_len(filename);
	count = count_lines(filename);
	lines = malloc (sizeof (char *) * (count + 1));
	if (! lines)
		return (NULL);

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(lines);
		return (NULL);
	}
	while ((line = get_next_line(fd)))
	{
		lines[i] = line;
		++i;
	}
	lines[count] = NULL;
	close (fd);
	return (lines);
}
