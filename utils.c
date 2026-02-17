/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/17 16:48:48 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void free_map(char **map)
{
    int i = 0;

    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
	return ;
}

void print_map(char **map)
{
    int i = 0;

	while (map[i])
	{
		ft_printf("%s", map[i]);
		++i;
	}
	return ;
}

int count_lines(char **lines)
{
    int i = 0;

    while (lines[i])
        i++;
    return(i);
}

int	ft_strlen_map(char *s)
{
	int	i;

	i = 0;
	while (*s && (*s !='\n' && *s !='\0'))
	{
		++i;
		++s;
	}
	return (i);
}

void ft_strncpy_map(char *dest, const char *src)
{
	int i;
	
	if (!dest || !src)
		return;
	i = 0;
	while ((src[i] != '\0') && (src[i] != '\n'))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return;
}
