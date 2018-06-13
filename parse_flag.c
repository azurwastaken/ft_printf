
char	*parse_flag(char *str, t_flag *flag)
{
	if(str[1] == '-' || str[1] == '+' || str[1] == ' ' || str[1] == '0')
	{
		flag->is_flag = 1;
		if(str[1] == '-')
			flag->right_just = 1;
		else if(str[1] == '+')
			flag->en_sign = 1;
		else if(str[1] == ' ')
			flag->spacef = 1;
		else if(str[1] == '0')
			flag->fill_zero = 1;
	}
	else
		flag->is_flag = 0;
	return(str);
}

int		is_prec(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if(str[i] == '.')
			res = 1;
		i++;
	}
	return(0);
}

char	*parse_width(char *str, t_flag *flag)
{
	char **split;

	flag->precision = 0;
	if (is_prec(str))
	{
		split = ft_strsplit(str, '.');
		flag->precision = ft_atoi(split[1]);
		if(flag->is_flag == 1)
			flag->width = ft_atoi(&split[0][2]);
		else
			flag->width = ft_atoi(&split[0][1]);
	}
	else
	{
		if(flag->is_flag == 1)
			flag->width = ft_atoi(&str[2]);
		else
			flag->width = ft_atoi(&str[1]);			
	}
	return(str);
}