
#include "lib_printf.h"

char		*s_case(char *str, va_list va, t_flag *flag)
{
	free(str);
	flag->fill_zero = 0;
	//if(ft_strcmp(flag->length,"l"))
	//	str = ft_strdup(va_arg(va, wchar_t *));
	/*else*/ if(flag->length == NULL)
		str = ft_strdup(va_arg(va, char*));
	if(str[0] != '\0' && str[0])
		flag->spacef = 0;
	return(str);
}

char		*c_case(char *str, va_list va, t_flag *flag)
{
	char c;
	//char *tmp;

	ft_strdel(&str);
	flag->spacef = 0;
	flag->fill_zero = 0;
	if(flag->length == NULL)
	{
		c = (char)va_arg(va, int);
		str = ft_strdup(&c);
	}
	//if(ft_strcmp(flag->length,"l") == 0)
	//	c = va_arg(va, wchar_t);
	return(str);
}

char		*d_case(char *str, va_list va, t_flag *flag)
{
	free(str);
	flag->fill_zero = 0;
	if(flag->length == NULL)
		str = ft_convert_base((long long)va_arg(va, int), 10, 'd');
	else if(ft_strcmp(flag->length,"l") == 0)
		str = ft_convert_base((long long)va_arg(va, long), 10, 'd');
	else if(ft_strcmp(flag->length,"ll") == 0)
		str = ft_convert_base(va_arg(va, long long), 10, 'd');
	else if(ft_strcmp(flag->length,"h") == 0)
		str = ft_convert_base((long long)((signed short)va_arg(va, int)), 10, 'd');
	else if(ft_strcmp(flag->length,"hh") == 0)
		str = ft_convert_base((long long)((char)va_arg(va, int)), 10, 'd');
	else if(ft_strcmp(flag->length,"j") == 0)
		str = ft_convert_base((long long)va_arg(va, intmax_t), 10, 'd');
	else if(ft_strcmp(flag->length,"z") == 0)
		str = ft_convert_base((long long)va_arg(va, size_t), 10, 'd');
	
	return(str);
}

char		*oux_case(char *str, va_list va, t_flag *flag)
{
	int base;

	flag->fill_zero = 0;
	if(flag->specifier == 'x' || flag->specifier == 'X')
		base = 16;
	else if(flag->specifier == 'o' || flag->specifier == 'O')
		base = 8;
	else if(flag->specifier == 'u' || flag->specifier == 'U')
		base = 10;
	free(str);
	if(flag->length == NULL)
		str = ft_convert_base((long)va_arg(va, unsigned int), base, flag->specifier);
	else if(ft_strcmp(flag->length,"l") == 0)
		str = ft_convert_base((long)va_arg(va, unsigned long), base, flag->specifier);
	else if(ft_strcmp(flag->length,"ll") == 0)
		str = ft_convert_base((long)va_arg(va, unsigned long long), base, flag->specifier);
	else if(ft_strcmp(flag->length,"h") == 0)
		str = ft_convert_base((long)((unsigned char)va_arg(va, int)), base, flag->specifier);
	else if(ft_strcmp(flag->length,"hh") == 0)
		str = ft_convert_base((long)((unsigned short)va_arg(va, int)), base, flag->specifier);
	else if(ft_strcmp(flag->length,"j") == 0)
		str = ft_convert_base((long)va_arg(va, uintmax_t), base, flag->specifier);
	else if(ft_strcmp(flag->length,"z") == 0)
		str = ft_convert_base((long)va_arg(va, size_t), base, flag->specifier);
	else if(flag->length == NULL)
		str = ft_convert_base((long)va_arg(va, unsigned int), base, flag->specifier);
	return(str);
}

char		*p_case(char *str, va_list va, t_flag *flag)
{
	if(flag->length == NULL)
		str = hashtag_case(ft_convert_base((long)va_arg(va, void *), 16, 'x'), flag);
	return(str);
}

char		*percent_case(char *str)
{
	free(str);
	str = ft_strdup("%");
	return(str);
}