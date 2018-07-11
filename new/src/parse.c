#include "lib_printf.h"

char	*parse_flag(char *format, t_flag *flag)
{
	while (is_charset(*format, "-+ 0#"))
	{
		flag->is_flag = 1;
		if (*format == '-')
			flag->right_just = 1;
		else if (*format == '+')
			flag->en_sign = 1;
		else if (*format == ' ')
			flag->spacef = 1;
		else if (*format == '0')
			flag->fill_zero = 1;
		else if (*format == '#')
			flag->put_prefix = 1;
		format++;
	}
	if (flag->right_just == 1)
		flag->fill_zero = 0;
	if (flag->en_sign == 1)
		flag->spacef = 0;
	return (parse_width(format, flag));
}

char	*parse_width(char *format, t_flag *flag)
{
	flag->width = ft_atoi(format);
	while(is_charset(*format, "0123546789"))
		format++;
	return(parse_prec(format, flag));
}

char	*parse_prec(char *format, t_flag *flag)
{
	if(*format == '.')
	{
		flag->fill_zero = 0;
		format++;
		flag->isprec = 1;
		flag->precision = ft_atoi(format);
		while(is_charset(*format, "0123546789"))
			format++;
	}
	return(parse_length(format, flag));
}

char	*parse_length(char *format, t_flag *flag)
{
	if (*format == 'h')
	{
		flag->length = format[1] == 'h' ? ft_strdup("hh") : ft_strdup("h");
		format += ft_strcmp(flag->length, "hh") == 0 ? 2 : 1;
		flag->is_length = 1;
	}
	else if (*format == 'l')
	{
		flag->length = format[1] == 'l' ? ft_strdup("ll") : ft_strdup("l");
		format += ft_strcmp(flag->length, "ll") == 0 ? 2 : 1;
		flag->is_length = 1;
	}
	else if (*format == 'j')
	{
		flag->length = ft_strdup("j");
		format += (flag->is_length = 1);
	}
	else if (*format == 'z')
	{
		flag->length = ft_strdup("z");
		format += (flag->is_length = 1);
	}
	else
		flag->is_length = 0;
	return (format);
}