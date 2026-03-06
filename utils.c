/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/23 17:59:38 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_strncpy(char *dest, const char *src)
{
	int	i;

	if (!dest || !src)
		return ;
	i = 0;
	while ((src[i] != '\0'))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return ;
}

void	error(void)
{
	ft_printf("Error\n");
}

void	error_msg(char *msg)
{
	ft_printf("Error\n");
	if (msg)
		ft_printf("%s\n", msg);
	return ;
}
