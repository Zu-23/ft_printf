/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:17:34 by zhaddoum          #+#    #+#             */
/*   Updated: 2021/12/14 18:40:54 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
int		ft_putstr(char *str);
int		ft_putnbr(long a, int i);
int		ft_putchar(char c);
int		ft_hexconv(unsigned long int i, char c);
int		ft_printf(const char * c, ...);
int		ft_print_str(char *str);

#endif
