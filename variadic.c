#include<stdio.h>
#include<stdarg.h>
#include<unistd.h>

void	eval_func(char *c, int i, int a)
{
	if (c[i] == 'c')
	{
		write (1, &a, 1);
	}
	return ;
}

int	ft_printf(char *c, ...)
{
	int		i;
	int	k;

	va_list arg;
	va_start(arg, c);
	i = -1;
	while(c[++i])
	{
		if (c[i] == '%' && (c[i +1] == 'c' || c[i +1] == 'd' || c[i +1] == 'i'))
		{
			k =  va_arg(arg, int);
			eval_func(c, i + 1, k);
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
	ft_printf("hello %c",a);
}