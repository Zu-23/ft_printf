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





void	eval_func(char *c, int i, int a)
{
	if (c[i] == 'c')
		write (1, &a, 1);
	if (c[i] == 'd' || c[i] == 'i')
	{
		putnbr(a);
	}
	return ;
}

int	ft_printf(char *c, ...)
{
	int		i;
	int		k;
	char 	*str;

	va_list arg;
	va_start(arg, c);
	i = -1;
	while(c[++i])
	{
		if (c[i] == '%')
		{
			if ((c[i + 1] == 'c' || c[i + 1] == 'd' || c[i + 1] == 'i'))
			{
				k =  va_arg(arg, int);
				eval_func(c, i + 1, k);
			}
			else if (c[i + 1] == 's')
			{
				str = va_arg(arg, char *);
				ft_putstr(str);
			}
			else if (c[i + 1] == 'p')
			{
				k = (unsigned int) va_arg(arg, unsigned int);
				printf("%u 		",k);
        		printf("%#x  	",k);

			}


			i++;
		}
		else
			write (1, &c[i], 1);
	}
	return (0);
}

int main()
{
	int a = 67;
	char *str;
	ft_printf("%p", &str);
	printf("		%p", &str);
}