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
	wint_t car = L'δ';
	int a,b;
	a = ft_printf("%o, %ho, %hho\n", -42, -42, -42);
	b = printf("%d", car);
	printf("\na = %d b = %d",a,b);
	return(0);
}
