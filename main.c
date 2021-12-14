#include<stdio.h>
#include "ft_printf.h"

int main()
{
	// int d = printf(" NULL %s NULL ", NULL);
	// printf("%d \n", d);

	// int d = ft_printf(" NULL %s NULL ", NULL);
	// printf("%d\n", d);
	int a = 35212;
	char c = '\0';
	char *str = "testing 	int			sf";
	void	*ptr;
	ft_printf("%d	%c	%s	%p	%u	%x	%X	",a,c,str,&ptr,a,a,a);
}