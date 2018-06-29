#include "lib_printf.h"

/*char	*length_handler(char *str, t_flag flag)
{
	if(flag->en_sign == 1 && is_unint(flag->specifier))
}*/

char	*is_charset(char c, char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if(c == str[i])
			return(1);
		i++;
	}
	return(0);
}

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

char	*precision_handler(char *str, t_flag flag)
{
	int str_len;

	str_len = ft_strlen(str);
	if(is_charset(flag->specifier, "diouxX"))
	{
		if(str[0] == '-')
		{
			str_len--;
			str = ft_strjoin(create_str('0', str_len - flag->precision, 1), &str[1]);
		}
	}
}

char	*width_handler(char *str, t_flag flag)
{
	if(!(flag->fill_zero))
	{
		flag->width -= ft_strlen(str);
		if(flag->width > 0)
			str = ft_strjoin(create_str(' ', flag->width),str);
	}
	else
	{

	}
}