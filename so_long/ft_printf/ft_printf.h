/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2025/08/11 16:25:20 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);

int	ft_putchar(char c);
int	ft_putnbr(int n);

int	ft_printstr(char *s);
int	ft_put_p(char c);
int	ft_printhex(unsigned long long n);
int	ft_printhex_big(unsigned long long n);
int	ft_print_unsigned(unsigned int n);
int	ft_printf_ptr(void *ptr);

#endif
