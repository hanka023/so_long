/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2025/08/11 15:50:39 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

int	ft_ptr_len(unsigned long long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	ft_printf_ptr(void *ptr)
{
	uintptr_t	address;
	int			len;

	len = 0;
	if (ptr == NULL)
		return (ft_printstr("(nil)"));
	address = (uintptr_t)ptr;
	len += write(1, "0x", 2);
	len += ft_printhex((unsigned long long)address);
	return (len);
}
