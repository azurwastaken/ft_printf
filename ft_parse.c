#include "lib_printf.h"


static int is_flag_unint(char c)
{
	if(c == 'l' || c == 'h'|| c == 'j' || c == 'z' || c == 'd' || c == 'D' || c == 'i' || c == 'z' || c == 'o' || c == 'O' || c == 'u' || c == 'U')
		return(1);
	return(0);
}

static int		count_flag(char *format)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while(format[i] != '\0')
	{
		if(format[i] == '%' || format[i] == ' ')
			res++;
		if(format[i] == ' ' && is_flag_unint(format[i + 1]))
			res--;
		while(format[i] == ' ')
			i++;
		i++;
	}
	return(res);
}


static char	*get_str(char *format, int *j)
{
	int i;
	char *str;

	i = 0;
	if(format[0] == '%')
	{
	while(format[i] == '%')
		i++;
	if(format[i] == ' ' && is_flag_unint(format[i + 1]))
		i++;
	}
	else if(format[0] == ' ')
	{
	while(format[i] == ' ')
		i++;
	}
	while(format[i] != '%' && format[i] != '\0' && format[i] != ' ')
		i++;
	if(!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return(0);
	str[i] = '\0';
	*j = i == 0 ? *j + 1 : *j + i;
	i--;
	while(i >= 0)
	{
		str[i] = format[i];
		i--;
	}
	return(str);
}
char	**ft_parse(char *format)
{
	char	**split;
	int		nb_flag;
	int		i;
	int		j;

	i = 0;
	j = 0;
	printf("format = %s\n",format);
	nb_flag = count_flag(format);
	if(!(split = (char **)malloc(sizeof(char*) * (nb_flag + 1))))
		return(0);
	while(i < nb_flag)
	{
		//printf("parse i = %d\n",nb_flag);
		split[i] = get_str(&format[j],&j);
		i++;
	}
	split[i] = NULL;
	return(split);
}