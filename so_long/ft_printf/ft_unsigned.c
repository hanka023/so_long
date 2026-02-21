/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2025/08/07 16:45:06 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

static int	numlen_unsigned(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n > 0)
	{
		n = n / 10;
		++len;
	}
	return (len);
}

int	ft_print_unsigned(unsigned int n)
{
	int		len;
	char	*str;
	int		printed_len;

	len = numlen_unsigned(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[--len] = (n % 10) + '0';
		n = n / 10;
	}
	printed_len = ft_printstr(str);
	free(str);
	return (printed_len);
}
