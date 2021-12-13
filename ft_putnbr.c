#include<stdio.h>
#include<stdarg.h>
#include<unistd.h>
#include "ft_putstr.c"
#include "ft_putchar.c"
void	ft_putnbr(int a)
{
	if (a < 0)
	{
		a *= -1;
		write (1, "-", 1);
	}
	if (a > 9)
	{
		ft_putnbr(a / 10);
		ft_putnbr(a % 10);
	}
	if (a < 9)
	{
		a += '0';
		write (1, &a, 1);
	}
}