/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_printf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:36:53 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/01/29 13:53:27 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PRINTF_H
# define LIB_PRINTF_H

#include "../libft/libft.h"
#include <stdarg.h>
#include <wchar.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdint.h>

typedef struct s_flags
{
	int		is_flag;
	int		is_neg;
	int		right_just;
	int		en_sign;
	int		spacef;
	int		fill_zero;
	int		put_prefix;
	int		isprec;
	int		precision;
	int		width;
	char	*length;
	int		is_length;
	char	specifier;
	int		nb_percent;
	long long save;
	char	buffer[4096];
	int		i;
	int		res;
}	t_flag;

t_flag	*init_t_flag(void);
char	*parse_flag(char *str, t_flag *flag);
int		is_charset(char c, char *str);
char	*parse_width(char *format, t_flag *flag);
char	*parse_prec(char *format, t_flag *flag);
char	*parse_length(char *format, t_flag *flag);
int		ft_printf(const char *restrict format, ...);
char	*func_hub(va_list va, t_flag *flag);
char	*s_case(char *str, va_list va, t_flag *flag);
char *ft_print_unicode(wchar_t c, char *str);
char		*c_case(char *str, va_list va, t_flag *flag);
char		*d_case(char *str, va_list va, t_flag *flag);
char		*oux_case(char *str, va_list va, t_flag *flag);
char		*p_case(char *str, va_list va, t_flag *flag);
char		*percent_case(char *str, t_flag *flag);
char	*ft_convert_base(unsigned long long num, int base, char letter);
char			*ft_lltoa(long long n);
void	put_flag(t_flag *flag, va_list va);
int		calc_len(t_flag *flag, int str_len);
//void	test_t_flag(t_flag *flag);
char	*ft_convert_bde(long long num, int base, char letter);
char	*parse_main(char *format, t_flag *flag);
t_flag 	*reset_flag(t_flag *flag);
void	ft_putwchar(wchar_t c);

#endif
