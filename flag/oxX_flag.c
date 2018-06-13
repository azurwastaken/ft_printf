
char		*ft_convert_base(long num, int base, char letter)
{
	static char 	digit[] = "0123456789ABCDEF";
	static char 		buffer[50];
	char 		*res;
	int i;

	i = 10;
	while(i < 16 && letter == 'x')
	{
		digit[i] = ft_tolower(digit[i]);
		i++;
	}
	res = &buffer[49];
	*res = '\0';
	*--res = digit[num % base];
	num = num / base;
	while(num != 0)
	{
		*--res = digit[num % base];
		num = num / base;
	}
	return(res);
}

void	o_case(va_)