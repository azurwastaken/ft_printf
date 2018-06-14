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

typedef struct s_flags
{
	int		is_flag;
	int		right_just;
	int		en_sign;
	int		spacef;
	int		fill_zero;
	int		put_prefix;
	int		precision;
	int		width;
	char	*length;
	int		is_length;
	char	specifier;
	int		nb_percent;
}	t_flag;

int     ft_printf(const char * restrict format, ...);
char	**ft_parse(char *format);
char	*parse_flag(char *str, t_flag *flag);
int		is_prec(char *str);
int		get_end_nb(char *str);
char	*parse_width(char *str, t_flag *flag, int i);
char	*parse_length(char *str, t_flag *flag, int i);
char	*parse_specifier(char *str, t_flag *flag, int i);

#endif
