#include "lib_printf.h"

void	print_flag(int *save, int *i, char *str, t_flag *flag)																	//variable save, str, i, flag, 
{
	*save = ft_strlen(str);
	*i = 0;
	if (flag->right_just)
	{
		ft_putstr(str);
		if (flag->nul_case)
			write(1, "", 1);
		while (*i < flag->width - (*save + flag->nul_case))
		{
			write(1, " ", 1);
			*i += 1;
		}
	}
	else
	{
		while (*i < flag->width - (*save + flag->nul_case))
		{
			write(1, " ", 1);
			*i += 1;
		}
		ft_putstr(str);
		if (flag->nul_case)
			write(1, "", 1);
	}
}

void	delete_str(char **tmp, char **str, t_flag *flag)
{
	if (*str[0] != '\0')
		ft_strdel(str);
	if (*tmp[0] != '\0' && flag->specifier != 's')
		ft_strdel(tmp);
}