#include "lib_printf.h"

char	*func_hub(va_list va, t_flag *flag)
{
	char *str;

	str = NULL;
	if (flag->specifier == '%')
		str = percent_case(str);
	else if (flag->specifier == 's')
		str = s_case(str, va, flag);
	else if (flag->specifier == 'c')
		str = c_case(str, va, flag);
	else if (flag->specifier == 'p')
		str = p_case(str, va, flag);
	else if (flag->specifier == 'd')
		str = d_case(str, va, flag);
	else if (flag->specifier == 'i')
		str = d_case(str, va, flag);
	else if (flag->specifier == 'o')
		str = oux_case(str, va, flag);
	else if (flag->specifier == 'u')
		str = oux_case(str, va, flag);
	else if (flag->specifier == 'x' || flag->specifier == 'X')
		str = oux_case(str, va, flag);
	return (str);
}