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

int     ft_printf(const char * restrict format, ...);
char	**ft_parse(char *format);

#endif
