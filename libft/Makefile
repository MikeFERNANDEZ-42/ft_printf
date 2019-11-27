# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/26 18:12:51 by mifernan          #+#    #+#              #
#    Updated: 2019/11/25 12:05:47 by mifernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC = 	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_putnbr_fd.c \
		ft_memmove.c ft_memset.c ft_strchr.c ft_putendl_fd.c \
		ft_strdup.c  ft_toupper.c ft_strlcpy.c ft_putstr_fd.c ft_strndup_free.c\
		ft_strjoin.c ft_strlcat.c ft_strlen.c ft_split.c ft_putchar_fd.c\
		ft_strncmp.c ft_strnstr.c ft_calloc.c ft_itoa.c ft_strmapi.c ft_strdel.c \
		ft_strrchr.c ft_split.c ft_substr.c ft_strtrim.c ft_tolower.c ft_strjoin_free.c

BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c  \
		ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJ = $(SRC:.c=.o)

OBJBONUS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) libft.h
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(OBJBONUS)

fclean: clean
	rm -f $(NAME) 

re: fclean all

bonus: $(OBJBONUS)
	ar rc $(NAME) $(OBJBONUS)
	ranlib $(NAME)

.PHONY : clean fclean all re bonus
