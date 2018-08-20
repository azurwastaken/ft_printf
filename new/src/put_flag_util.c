#include "lib_printf.h"

int		put_ddi_sign(t_flag *flag, char **tmp, char *str, int *save)
{
	if (is_charset(flag->specifier, "dDi"))										// on s'occupe de mettre un signe si besoin          variable : flag, tmp, str, i, save
	{
		if (*tmp[0] == '-')
		{
			str[0] = **tmp;
			*tmp += 1;
			*save -= 2;
			return(1);
		}
		else if (flag->en_sign || flag->spacef)
		{
			str[0] = flag->en_sign && !(flag->spacef) ? '+' : ' ';
			*save -= 1;
			return(1);
		}
	}
	return(0);
}

void put_ooxxp_prefix(t_flag *flag, char *str, int *i, int *save)
{
	if (is_charset(flag->specifier, "oOxXp") && flag->put_prefix)					//same mais pour oOxXp 								variable : flag, str, i, save
	{
		str[*i] = '0';
		*i += 1;
		if (is_charset(flag->specifier, "xXp"))
		{
			str[*i] = flag->specifier == 'X' ? 'X' : 'x';
			*i += 1;
		}
		if (flag->specifier == 'p')
			*save -= 2;
	}
}

void handle_prec_num(t_flag *flag, int *save, int *i, char *str)
{
	if (flag->isprec && is_charset(flag->specifier, "pdDioOuUxX"))						//gere la precision + width							variable : flag, save, i, str, 
	{
		if (is_charset(flag->specifier, "xX") && flag->put_prefix)
			*save -= 2;
		while (*i < (flag->precision - *save))
		{
			str[*i] = '0';
			*i += 1;
		}
	}
}

int handle_prec_str(t_flag *flag, int *i, char *tmp , char *str)
{
	while (*i < flag->precision)
	{
		str[*i] = tmp[*i];
		*i += 1;
	}
	return(*i);
}

void	handle_fill_zero(t_flag *flag, int *save, int *i, char *str)
{
	if ((!flag->isprec) && flag->fill_zero == 1)
	{
		if (flag->en_sign || str[0] == '-' || flag->spacef)
			*save += 1;
		while (*i < (flag->width - (*save + flag->nul_case)))
		{
			str[*i] = '0';
			*i += 1;
		}
	}
}