/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:58:13 by zhaddoum          #+#    #+#             */
/*   Updated: 2021/12/14 18:51:03 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_int_char(char c, int a)
{
	int	i;

	i = 0;
	if (c == 'c')
	{
		c = (char) a;
		write (1, &c, 1);
		i++;
	}
	else
		i += ft_putnbr(a, 0);
	return (i);
}

static int	ft_print_hex(char c, unsigned int a)
{
	if (c == 'x' || c == 'X')
		return (ft_hexconv(a, c));
	else
		return (ft_putnbr(a, 0));
}

static int	ft_print_ptr(unsigned long int a)
{
	int	i;

	i = 0;
	if (!a)
	{
		i += ft_putstr("(nil)");
		return (i);
	}
	i += ft_putstr("0x");
	i += ft_hexconv(a, 'p');
	return (i);
}

static int	eval(va_list arg, char c)
{
	int	ret;

	ret = 0;
	
	if ((c == 'c' || c == 'd' || c == 'i'))
		ret += ft_print_int_char(c, va_arg(arg, int));
	else if (c == 's')
		ret += ft_print_str(va_arg(arg, char *));
	else if (c == 'x' || c == 'X' || c == 'u' )
		ret += ft_print_hex(c, va_arg(arg, unsigned int));
	else if (c == 'p')
		ret += ft_print_ptr(va_arg(arg, unsigned long long));
	else if (c == '%')
		ret += ft_putchar('%');
	return (ret);
}

int	ft_printf(const char *c, ...)
{
	int		i;
	int		ret;
	va_list	arg;

	va_start(arg, c);
	i = -1;
	ret = 0;
	while (c[++i])
	{
		if (c[i] == '%')
		{
			ret += eval(arg, c[i + 1]);
			i++;
		}
		else
		{
			write (1, &c[i], 1);
			ret++;
		}
	}
	va_end(arg);
	return (ret);
}
