#include "lib_printf.h"

void		special_case(t_flag *flag)
{
	if(flag->specifier == 'D' || flag->specifier == 'O' || flag->specifier == 'U')
	{
		ft_tolower(flag->specifier);
		flag->length = "l";
	}
}

int		is_flag(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i' ||
			c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' ||
			c == 'X' || c == 'c' || c == 'C' || c == '%')
		return (1);
	return (0);
}