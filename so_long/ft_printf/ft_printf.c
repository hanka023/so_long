/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanka <hanka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/01 11:40:48 by hanka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formats(va_list *args, const char str)
{
	int	len;

	len = 0;
	if (str == 'c')
		len += ft_putchar(va_arg(*args, int));
	else if (str == 'i' || str == 'd')
		len += ft_putnbr(va_arg(*args, int));
	else if (str == 's')
		len += ft_printstr(va_arg(*args, char *));
	else if (str == 'u')
		len += ft_print_unsigned(va_arg(*args, unsigned int));
	else if (str == 'x')
		len += ft_printhex(va_arg(*args, unsigned int));
	else if (str == 'X')
		len += ft_printhex_big(va_arg(*args, unsigned int));
	else if (str == 'p')
		len += ft_printf_ptr(va_arg(*args, void *));
	else
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, str);
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			len += ft_formats(&args, *str);
		}
		else
			len += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (len);
}

// int main(int argc, char *argv[])
// {
// 	if (argc < 2)
// 		return (0);

// 	int i = 1;
// 	while (i < argc)
// 	{
// 		//ft_printf("arg[%d] = '%s'\n", i, argv[i]);
// 		//ft_printf("%s %d\n", argv[i],i );

// 		//ft_printf(" %s %s\n",  argv[i], argv[i]);
// 		ft_printf(" %d %c\n", i, i);

// 		++i;
// 	}
// 	return (0);
// }
