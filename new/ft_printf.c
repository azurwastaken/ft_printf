#include "lib_printf.h"

int		ft_printf(const char *restrict format, ...)
{
	t_flag *flag;
	va_list va;

	flag = init_t_flag();
	if(!format)
		return(0);
	// parcourir format
	while(*format != '\0')
	{
	// stocker le tout dans un buffer de 4096
		while(*format != '%' && flag->i < 4095 && *format != '\0')
			flag->buffer[flag->i++] = *format++;
		if(flag->i == 4095)
		{
			write(1,flag->buffer,4096);
			flag->i = 0;
		}
		// si c'est un flag
		if(*format == '%')
		{
			flag->buffer[flag->i] = '\0';
			write(1,flag->buffer,flag->i);
			flag->i = 0;
		// commencer le traitement
			format++;
			while(!is_charset(*format,"sSpdDioOuUxXcC%") && *format != '\0')
			{
				format = parse_flag((char *)format, flag);
			}
			if(is_charset(*format,"sSpdDioOuUxXcC%"))
				flag->specifier = *format++;
			put_flag(flag, va);
		}
	}
	flag->buffer[flag->i] = '\0';
	ft_putstr(flag->buffer);
	va_end(va);
	free(flag);
	return(0);
}