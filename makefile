# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcaseaux <mcaseaux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 14:14:51 by mcaseaux          #+#    #+#              #
#    Updated: 2018/01/29 12:01:46 by mcaseaux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf 
LIB = ./libft/libft.a
SRCS = ft_printf.c
OBJS = ft_printf.o

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	make -C libft/ clean
	gcc -Wall -Wextra -Werror $(SRCS) main.c $(LIB) -o $(NAME)

clean:
	/bin/rm -f $(OBJS)
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
