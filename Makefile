# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/05 12:11:29 by mregada-          #+#    #+#              #
#    Updated: 2025/04/09 19:26:58 by mregada-         ###   ########.fr        #
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
		$(PRINTF_DIR)/char_handler.c $(PRINTF_DIR)/ft_puthex.c \
		$(PRINTF_DIR)/pointer_handler.c $(PRINTF_DIR)/ft_printf.c \
		$(PRINTF_DIR)/ft_putdec.c $(PRINTF_DIR)/str_handler.c \
		$(PRINTF_DIR)/Libft_src/ft_itoa.c $(PRINTF_DIR)/Libft_src/ft_strlen.c \
		$(PRINTF_DIR)/Libft_src/ft_putchar_fd.c main_ps.c \
		$(PRINTF_DIR)/Libft_src/ft_putstr_fd.c 

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g -I. -I$(PRINTF_DIR)

## COMPILAR EJECUTABLE ##

all : $(NAME)

$(NAME) : $(OBJS)
		clang $(CFLAGS) $(OBJS) -o $(NAME)


## COMPILAR OBJETOS ##

%.o: %.c $(HEADRS) Makefile
		cc $(CFLAGS) -c $< -o $@

## PHONYS ##

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)
	
re : fclean all

.PHONY: all clean fclean re
