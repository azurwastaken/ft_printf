# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcaseaux <mcaseaux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/14 15:52:21 by mcaseaux          #+#    #+#              #
#    Updated: 2018/08/23 14:36:14 by mcaseaux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft

SRCS =	ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_bzero.c\
			ft_memalloc.c\
			ft_memchr.c\
			ft_lstmap.c\
			ft_lstiter.c\
			ft_lstdel.c\
			ft_lstadd.c\
			ft_lstnew.c\
			ft_lstdelone.c\
			ft_memcmp.c\
			ft_memccpy.c\
			ft_memcpy.c\
			ft_memdel.c\
			ft_memmove.c\
			ft_memset.c\
			ft_putchar.c\
			ft_putchar_fd.c\
			ft_putendl.c\
			ft_putendl_fd.c\
			ft_putnbr.c\
			ft_putnbr_fd.c\
			ft_putstr.c\
			ft_putstr_fd.c\
			ft_atoi.c\
			ft_itoa.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_strcat.c\
			ft_strchr.c\
			ft_strclr.c\
			ft_strcmp.c\
			ft_strncmp.c\
			ft_strcpy.c\
			ft_strdel.c\
			ft_strdup.c\
			ft_strequ.c\
			ft_striter.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strjoinfree.c\
			ft_strlcat.c\
			ft_strlen.c\
			ft_strmap.c\
			ft_strmapi.c\
			ft_strncat.c\
			ft_strncmp.c\
			ft_strncpy.c\
			ft_strnequ.c\
			ft_strnew.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strsplit.c\
			ft_strstr.c\
			ft_strsub.c\
			ft_btree_apply_by_level.c\
			ft_btree_apply_infix.c\
			ft_btree_apply_prefix.c\
			ft_btree_apply_suffix.c\
			ft_btree_create_node.c\
			ft_btree_insert_data.c\
			ft_btree_level_count.c\
			ft_btree_search_item.c\
			ft_strtrim.c

OBJS =	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	gcc -Wall -Wextra -Werror -c $(SRCS) -I $(HEADER)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
