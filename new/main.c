#include "./src/lib_printf.h"
#include <limits.h>

int main(void)
{
	// int a,b;
	// a = ft_printf("%lX, %lX\n", 0, ULONG_MAX);
	// write(1,"\n",1);
	// b = printf("%lX, %lX\n", 0, ULONG_MAX);
	// printf("\na = %d b = %d",a,b);
	//printf("%05c\n", 42);
	int a,b;
	a = ft_printf("%.0p, %.p\n", 0,0);
	b = printf("%.0p, %.p\n", 0,0);
	printf("\na = %d b = %d",a,b);
	return(0);
}
