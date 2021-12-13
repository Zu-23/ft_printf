#include<stdio.h>
#include<stdarg.h>
#include<unistd.h>
void	putnbr(int a)
{
	if (a < 0)
	{
		a *= -1;
		write (1, "-", 1);
	}
	if (a > 9)
	{
		putnbr(a / 10);
		putnbr(a % 10);
	}
	if (a < 9)
	{
		a += '0';
		write (1, &a, 1);
	}
}
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}





void	eval_func(char *c, int i, ...)
{
	va_list arg;
	va_start (arg, i);
	char k;
	int a;
	char *str;

	if (c[i] == 'c')
	{
		a = va_arg(arg, int);
		write (1, &a, 1);
	}
	if (c[i] == 'd' || c[i] == 'i')
	{
		a = va_arg(arg, int);
		putnbr(a);
	}
	va_end(arg);
	return ;
}

int	ft_printf(char *c, ...)
{
	int		i;
	va_list arg;
	va_start(arg, c);
	i = -1;
	while(c[++i])
	{
		if (c[i] == '%')
		{
			if ((c[i + 1] == 'c' || c[i + 1] == 'd' || c[i + 1] == 'i'))
				eval_func(c, i + 1, va_arg(arg, int));
			else if (c[i + 1] == 's')
				eval_func(c, i + 1, va_arg(arg, char *));
			else if (c[i + 1] == 'p')
				eval_func(c, i + i, va_arg(arg, unsigned int));
			i++;
		}
		else
			write (1, &c[i], 1);
	}
	va_end(arg);
	return (0);
}

int main()
{
	char a = 'c';
	printf("%%",a);
}