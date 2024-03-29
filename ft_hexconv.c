/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexconv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:58:49 by zhaddoum          #+#    #+#             */
/*   Updated: 2021/12/24 13:43:10 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexconv(unsigned long long i, char c)
{
	char		*base;
	static int	a;

	a = 0;
	if (c == 'x' || c == 'p')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	if (i < 16)
	{
		write(1, &base[i], 1);
		a += 1;
		return (a);
	}
	else
	{
		ft_hexconv(i / 16, c);
		write(1, &base[i % 16], 1);
		a += 1;
	}
	return (a);
}
