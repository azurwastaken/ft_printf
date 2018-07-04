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

#include "./libft/libft.h"
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
}	t_flag;

int		is_flag(char c);
int     ft_printf(const char * restrict format, ...);
char	**ft_parse(char *format);
char		*create_str(char c, int length, int is_neg);
char		*ft_convert_base(long long num, int base, char letter);
char	*parse_flag(char *str, t_flag *flag, va_list va);
int		is_prec(char *str);
int		get_end_nb(char *str);
char	*parse_width(char *str, t_flag *flag, int i, va_list va);
char	*parse_length(char *str, t_flag *flag, int i);
char	*parse_specifier(char *str, t_flag *flag, int i);
char		*s_case(char *str, va_list va, t_flag *flag);
char		*c_case(char *str, va_list va, t_flag *flag);
char		*p_case(char *str, va_list va, t_flag *flag);
char		*oux_case(char *str, va_list va, t_flag *flag);
char		*d_case(char *str, va_list va, t_flag *flag);
char		*percent_case(char *str);
void		special_case(t_flag *flag);
char			*ft_lltoa(long long n);
char	*hashtag_case(char *str, t_flag *flag);
char	*ft_strfreedup(char *src);
char	*precision_handler(char *str, t_flag *flag);
char	*width_handler(char *str, t_flag *flag);
int		is_charset(char c, char *str);

typedef char	*(*t_array)(char*, va_list, t_flag *);
#endif
