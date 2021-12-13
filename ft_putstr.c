
#include<stdio.h>
#include<stdarg.h>
#include<unistd.h>
#include "ft_putnbr.c"
#include "ft_putchar.c"
void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}
