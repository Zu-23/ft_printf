#include<stdio.h>
#include "ft_printf.h"
#include<limits.h>
int main()
{
	int a;
	// a = printf(" %d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// printf("%d\n",a);
	// a = ft_printf(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// printf(" %d\n",a);
	a = printf("%d %d",INT_MAX,INT_MIN);
	printf("\nvalue of a %d\n",a);
	a = ft_printf("%d %d",INT_MAX,INT_MIN);
	printf("\nvalue of a %d\n",a);
}