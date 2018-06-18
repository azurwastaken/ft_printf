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

char		*create_str(char c, int length, int is_neg)
{
	char *str;

	if(!(str != (char *)malloc(sizeof(char) * length + 1)))
		return(NULL);
	str[length--] = '\0';
	while(length > 0)
		str[length--] = c;
	return(str);
}

char		*zero_case(char *str, t_flag flag)
{
	int str_size;
	char *tmp;
	int is_neg;

	is_neg = 0;
	if(!(flag->isprec))
	{
		str_size = ft_strlen(str);
		if(flag->spacef)
			flag->width--;	
		if(flag->width > str_size)
		{
			if(str[0] = '-')
			{
				flag->is_neg = 1;
				tmp = ft_strjoinfree(create_str('0',width - str_size, is_neg), &str[1]);
				free(str);
				str = tmp;
			}
			else
				str = ft_strjoinfree(create_str('0',width - str_size, is_neg), &str[0]);
		}
	}
	return(0);
}

char		*plus_case(char *str)
{
	if(str[0] != '-')
		str = ft_strjoinfree("+", str);
}