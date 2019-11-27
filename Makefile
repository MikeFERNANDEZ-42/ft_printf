# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/26 18:12:51 by mifernan          #+#    #+#              #
#    Updated: 2019/11/26 12:07:32 by mifernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

LIBFT_PATH	=	./libft/

SRC =  ft_convert.c ft_convert_utils.c ft_parser_nb.c ft_parser_nb_utils.c \
ft_parser_ptr.c ft_parser_str.c ft_parser_utils.c ft_printf.c ft_split_printf.c \
ft_init_printf.c ft_parser_utils_str.c

SRC_LFT = $(addprefix ./libft/, ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_putnbr_fd.c \
	ft_memmove.c ft_memset.c ft_strchr.c ft_putendl_fd.c \
	ft_strdup.c  ft_toupper.c ft_strlcpy.c ft_putstr_fd.c ft_strndup_free.c\
	ft_strjoin.c ft_strlcat.c ft_strlen.c ft_split.c ft_putchar_fd.c\
	ft_strncmp.c ft_strnstr.c ft_calloc.c ft_itoa.c ft_strmapi.c ft_strdel.c\
	ft_strrchr.c ft_split.c ft_substr.c ft_strtrim.c ft_tolower.c ft_strjoin_free.c)

OBJS = $(SRC:.c=.o)

OBJS_LFT = $(SRC_LFT:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_LIBFT)
	make -C ./libft
	ar rc $(NAME) $(OBJS) $(OBJS_LFT)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $< -I$(LIBFT_PATH)

clean:
	make clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME) 

re: fclean all

.PHONY : clean fclean all re