#include "lib_printf.h"

int		ft_printf(const char *restrict format, ...)
{
	t_flag *flag;
	va_list va;
	char *save;

	flag = init_t_flag();
	va_start(va, format);
	flag->res = 0;
	if(!format)
		return(0);
	// parcourir format
	while(*format != '\0')
	{
		flag = reset_flag(flag);
	// stocker le tout dans un buffer de 4096
		while(*format != '%' && flag->i < 4095 && *format != '\0')
		{
			flag->buffer[flag->i++] = *format++;
			flag->res++;
		}
		if(flag->i == 4095)
		{
			write(1,flag->buffer,4096);
			flag->res += 4096;
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
			format = parse_main((char *)format, flag);
			while(!is_charset(*format,"sSpdDioOuUxXcC%") && *format != '\0' && is_charset(*format,"sSpdDioOuUxXcC%hljz 0+-#123456789"))
			{
				save = (char *)format;
				format = parse_main((char *)format, flag);
				if(!ft_strcmp(format, save))
					format++;
			}
			if(is_charset(*format,"sSpdDioOuUxXcC%"))
			{
				flag->specifier = *format++;
				if(flag->isprec && flag->specifier == '%')
					flag->isprec = 0;
				else if(flag->isprec)
					flag->fill_zero = 0;
				put_flag(flag, va);
			}
		}
	}
	flag->buffer[flag->i] = '\0';
	ft_putstr(flag->buffer);
	//flag->res += ft_strlen(flag->buffer);
	va_end(va);
	free(flag);
	return(flag->res);
}