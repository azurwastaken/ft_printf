#include "lib_printf.h"


static int is_flag(char c)
{
	if(c == 's' || c == 'S'|| c == 'p' || c == 'd' || c == 'D' || c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == '%')
		return(1);
	return(0);
}


static int		count_flag(char *format)
{
	int i;
	int res;
	int flag;

	i = 0;
	flag = 0;
	res = format[0] == '%' ? 0 : 1;
	while(format[i] != '\0')
	{
		if(format[i] == '%' || format[i] == ' ')
		{
			res++;
			if(format[i] == '%')
				flag = 1;
			while(flag == 1 && format[i] != '\0' && !(is_flag(format[i])))
				i++;
			res = (flag == 1 && format[i] != '\0') ? res + 1 : res;
			flag = 0;
		}
		if(format[i] == ' ')
		{
			while(format[i] == ' ')
				i++;
		}
		else
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
		i++;
	while(!(is_flag(format[i])) && format[i] != '\0')
		i++;
	i++;
	}
	else
	{
		if(format[0] == ' ')
		{
		while(format[i] == ' ')
			i++;
		}
		while(format[i] != '%' && format[i] != '\0' && format[i] != ' ')
			i++;
	}
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
	//printf("format = %s\n",format);
	nb_flag = count_flag(format);
	if(!(split = (char **)malloc(sizeof(char*) * (nb_flag + 1))))
		return(0);
	while(i < nb_flag)
	{
		split[i] = get_str(&format[j],&j);
		i++;
	}
	split[i] = NULL;
	return(split);
}