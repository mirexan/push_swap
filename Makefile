# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/05 12:11:29 by mregada-          #+#    #+#              #
#    Updated: 2025/04/08 21:12:09 by mregada-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## VARIABLES ##

NAME = pushswap
HEADRS = push_swap.h
SRCS_DIR = SRCS_LIBFT
PRINTF_DIR = ft_printf

## ARCHIVOS FUENTE ##

SRCS =  $(SRCS_DIR)/ft_add_to_stack.c $(SRCS_DIR)/ft_atoi.c \
		$(SRCS_DIR)/ft_lstclear.c $(SRCS_DIR)/ft_split.c \
		main_ps.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g -I. -I$(PRINTF_DIR)

## COMPILAR EJECUTABLE ##

all : $(NAME)

$(NAME) : $(OBJS)
		$(MAKE) -C $(PRINTF_DIR)
		clang $(CFLAGS) $(OBJS) $(PRINTF_DIR)/libftprintf.a -o $(NAME)


## COMPILAR OBJETOS ##

%.o: %.c $(HEADRS) Makefile
		cc $(CFLAGS) -c $< -o $@

## PHONYS ##

clean :
		rm -f $(OBJS)
		$(MAKE) -C $(PRINTF_DIR) clean

fclean : clean
		rm -f $(NAME)	
		$(MAKE) -C $(PRINTF_DIR) fclean

re : fclean all

.PHONY: all clean fclean re
