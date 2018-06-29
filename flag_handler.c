#include "lib_printf.h"

char		*space_case(char *str)
{
	if(str[0] != '-')
		str = ft_strjoin(" ", str);
	return(str);
}

char		*create_str(char c, int length, int is_neg)
{
	char *str;
	int i;

	length += is_neg;
	if(!(str = (char *)malloc(sizeof(char) * length)))
		return(0);
	i = 0;
	if(is_neg)
		str[i++] = '-';
	while(i < length)
		str[i++] = c;
	return(str);
}

/*char		*zero_case(char *str, t_flag flag)
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
				str[0] = '-';
			}
			else
				str = ft_strjoinfree(create_str('0',width - str_size, is_neg), &str[0]);
		}
	}
	return(0);
}*/

char		*plus_case(char *str)
{
	if(str[0] != '-')
		str = ft_strjoin("+", str);
	return(str);
}