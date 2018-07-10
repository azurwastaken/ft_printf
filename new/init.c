#include "lib_printf.h"

t_flag	*init_t_flag(void)
{
	t_flag *flag;

	if (!(flag = malloc(sizeof(t_flag))))
		return (0);
	flag->is_flag = 0;
	flag->right_just = 0;
	flag->en_sign = 0;
	flag->spacef = 0;
	flag->fill_zero = 0;
	flag->precision = 0;
	flag->isprec = 0;
	flag->width = 0;
	flag->length = NULL;
	flag->is_length = 0;
	flag->specifier = 0;
	flag->nb_percent = 0;
	flag->put_prefix = 0;
	flag->i = 0;
	return (flag);
}