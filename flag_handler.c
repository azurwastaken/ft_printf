#include "lib_printf.h"

char		*hashtag_case(char *str, t_flag flag)
{
	if(flag->specifier == 'o')
		flag->precision++;
	else if(flag->specifier == 'x')
		str = ft_strjoinfree("0x", str);
	else if(flag->specifier == 'X')
		str = ft_strjoinfree("0X", str);
}

char		*space_case(char *str, t_flag flag)
{
	if(str[0] != '-')
		str = ft_strjoinfree(" ", str);
}