#include<stdio.h>
#include<stdarg.h>
#include<unistd.h>
#include "ft_putnbr.c"
#include "ft_putstr.c"
void	ft_putchar(char c)
{
	write(1, &c, 1);
}