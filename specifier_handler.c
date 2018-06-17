
#include "lib_printf.h"

char		*s_case(char *str, va_list va, t_flag flag)
{
	free(str);
	str = ft_strdup(va_arg(va, char*));
	return(str);
}

char		*c_case(char *str, va_list va, t_flag flag)
{
	char c;
	free(str);
	c = va_arg(va, char);
	str = ft_strdup(&c);
	return(str);
}

char		*d_case(char *str, va_list va, t_flag flag)
{
	free(str);
	if()
	else
		str = ft_lltoa((long long)va_arg(va, int));
	return(str);
}

char		*o_case(char *str, va_list va, char letter, t_flag flag)
{
	free(str);
	str = ft_convert_base((long)va_arg(va, unsigned int), 8, letter);
	return(str);
}

char		*x_case(char *str, va_list va, char letter, t_flag flag)
{
	free(str);
	str = ft_convert_base((long)va_arg(va, unsigned int), 16, letter);
	return(str);
}

char		*u_case(char *str, va_list va, t_flag flag)
{
	
}