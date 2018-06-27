#include "lib_printf.h"

/*char	*length_handler(char *str, t_flag flag)
{
	if(flag->en_sign == 1 && is_unint(flag->specifier))
}*/

char	*hashtag_case(char *str, t_flag *flag)
{
	char *tmp;

	tmp = str;
	//free(str);
	if(flag->specifier == 'x' || flag->specifier == 'p')
		str = ft_strjoin("0x", tmp);
	else if(flag->specifier == 'X')
		str = ft_strjoin("0X", tmp);
	else if(flag->specifier == 'o' && str[0] != 0)
		str = ft_strjoin("0", tmp);
	return(str);
}