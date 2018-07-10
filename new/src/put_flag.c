#include "lib_printf.h"

int		calc_len(t_flag *flag, int str_len)
{
	int res;

	res = str_len + 1;
	if (is_charset(flag->specifier,"pdDioOuUxX%"))
	{
		res += flag->en_sign ? 1 : 0;
		res += flag->spacef ? 1 : 0;
		res += flag->isprec ? flag->precision : 0;
		if (flag->put_prefix && is_charset(flag->specifier,"oOxX"))
			res += is_charset(flag->specifier,"xX") ? 2 : 1;
		return (flag->width > res ? flag->width : res);
	}
	else if (flag->specifier == 'c')
		return (flag->width > res ? flag->width : res);
	else if (is_charset(flag->specifier,"s"))
	{
		res = res > flag->precision ? flag->precision : res;
		return (flag->width > res ? flag->width : res);
	}
	return(res);
}

void	put_flag(t_flag *flag, va_list va)
{
	char *str;
	char *tmp;
	int save;
	int i;


	i = 0;
	tmp = func_hub(va, flag);
	save = ft_strlen(tmp);
	if(!(str = (char *)malloc(sizeof(char) * (calc_len(flag, save)))))
		return ;
	if(flag->en_sign && tmp[0] != '-' && is_charset(flag->specifier,"dDi"))
		str[i++] = '+';
	// s'occuper des 0;
	if (is_charset(flag->specifier,"pdDi"))
	{
		str[0] = tmp[0] == '-' ? '-' : 0;
		i = tmp[0] == '-' ? 1 : 0;
	}
	else if (is_charset(flag->specifier,"oOxX") && flag->put_prefix)
	{
		str[i++] = '0';
		if(is_charset(flag->specifier,"xX"))
			str[i++] = flag->specifier == 'x' ? 'x' : 'X';
		printf("ZALU\n");
	}
	if (flag->isprec && is_charset(flag->specifier,"pdDioOuUxX"))
	{
		while(i < (flag->precision))
			str[i++] = '0';
		printf("ZALU 2\n");
	}
	else if (flag->isprec && flag->specifier == 's')
	{
		while (i < flag->precision)
		{
			str[i] = tmp[i];
			i++;
		}
		save = i;
	}
	else if ((!flag->isprec) && flag->fill_zero == 1)
	{
		while(i < (flag->width - save))
			str[i++] = '0';
		printf("ZALU3\n");
	}
	printf("ENDIF\n");
	// add str
	while(*tmp)
		str[i++] = *tmp++;
	str[i] = '\0';
	printf("ZALU 4\n");
	//print width
	save = ft_strlen(str);
	i = 0;
	while (i < flag->width - save)
	{
		write(1," ",1);
		i++;
	}
	printf("ZALU5\n");
	ft_putstr(str);
	if(str[0] != '\0')
		ft_strdel(&str);
	if(tmp[0] != '\0')
		ft_strdel(&tmp);
}