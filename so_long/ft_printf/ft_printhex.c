/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2025/08/11 15:49:59 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_printhex(unsigned long long num)
{
	char	*digits;
	char	str[16];
	int		i;
	int		len;

	digits = "0123456789abcdef";
	i = 0;
	len = 0;
	if (num == 0)
		return (write(1, "0", 1));
	while (num != 0)
	{
		str[i++] = digits[num % 16];
		num /= 16;
	}
	while (--i >= 0)
		len += write(1, &str[i], 1);
	return (len);
}

int	ft_printhex_big(unsigned long long num)
{
	char	*digits;
	char	str[16];
	int		i;
	int		len;

	digits = "0123456789ABCDEF";
	i = 0;
	len = 0;
	if (num == 0)
		return (write(1, "0", 1));
	while (num != 0)
	{
		str[i++] = digits[num % 16];
		num /= 16;
	}
	while (--i >= 0)
		len += write(1, &str[i], 1);
	return (len);
}
