# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/05 12:11:29 by mregada-          #+#    #+#              #
#    Updated: 2025/04/07 16:53:13 by mregada-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## VARIABLES ##

NAME = pushswap
HEADRS = push_swap.h

## ARCHIVOS FUENTE ##

SRCS = push_swap.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I $(HEADRS)

## REGLAS ##

all : $(NAME)

$(NAME) : $(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

## COMPILAR OBJETOS ##

%.o: %.c $(HEADRS) Makefile
		cc $(CFLAGS) -c $< -o $@

## PHONYS ##

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all
