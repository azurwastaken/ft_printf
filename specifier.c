#include "lib_printf"

void		special_case(t_flag *flag)
{
	if(flag->specifier == 'D' || flag->specifier == 'O' || flag->specifier == 'U')
	{
		ft_tolower(flag->specifier);
		flag->length = "l";
	}
}