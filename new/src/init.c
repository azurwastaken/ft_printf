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

void	test_t_flag(t_flag *flag)
{
	printf("is_flag = %d\n",flag->is_flag);
	printf("right just = %d\n",flag->right_just);
	printf("en_sign = %d\n",flag->en_sign);
	printf("spacef = %d\n",flag->spacef);
	printf("fill_zero = %d\n",flag->fill_zero);
	printf("precision = %d\n",flag->precision);
	printf("isprec = %d\n",flag->isprec);
	printf("width = %d\n",flag->width);
	printf("length = %s\n",flag->length );
	printf("islength = %d\n",flag->is_length);
	printf("specifier = %c\n",flag->specifier);
	printf("nb_percent = %d\n",flag->nb_percent);
	printf("put_prefix = %d\n",flag->put_prefix);
	printf("i = %d\n",flag->i);
}