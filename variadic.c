#include<stdio.h>
#include<stdarg.h>
#include<unistd.h>

void	eval_func(char *c, int i,va_list arg)
{
	if (c[i] == 'd')
	{
		int a = va_arg(arg,int);
		printf("%d", a);
	}
	return ;
}

int	ft_printf(char *c, ...)
{
	int	i;

	va_list arg;
	i = -1;
	while(c[++i])
	{
		if (c[i] == '%')
			eval_func(c, i + 1,arg);
		else
			printf("%c", c[i]);
	}
	return (0);
}

int main()
{
	int a = 3;
	ft_printf("hello %d",a);
}