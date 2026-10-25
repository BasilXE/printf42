# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: basayoub <basayoub@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/25 23:14:09 by basayoub          #+#    #+#              #
#    Updated: 2026/10/25 23:15:32 by basayoub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CF = -Wall -Wextra -Werror
SRC = ft_printf.c ft_printfparts.c

OBJ = $(SRC:.c=.o)
AR = ar
ARF = rsc

all : $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARF) $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CF) -c $< -o $@
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all

.PHONY : all fclean clean re