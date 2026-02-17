/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/17 16:38:56 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

void free_lines(char **lines)
{
    int i = 0;

    while (lines[i])
    {
        free(lines[i]);
        i++;
    }
    free(lines);
}

int count_lines_filename(char *filename)
{
	int fd;
	char *line;
	int lines;

	lines = 0;
	fd = open(filename, O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		++lines;
		free(line);
	}
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
	len = ft_strlen_map(line);
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

	i = 0;
	count = count_lines_filename(filename);
	lines = malloc (sizeof (*lines) * (count + 1));
	if(!lines)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free_lines(lines);
		return (NULL);
	}
	while (i < count && (line = get_next_line(fd)))
	{
		lines[i] = line;
		++i;
	}
	lines[count] = NULL;
	close(fd);
	return (lines);
}
