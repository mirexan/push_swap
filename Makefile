# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/05 12:11:29 by mregada-          #+#    #+#              #
#    Updated: 2025/04/26 18:29:26 by mregada-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## VARIABLES ##

NAME = push_swap
HEADRS = push_swap.h
SRCS_DIR = SRCS_LIBFT
PRINTF_DIR = ft_printf

## ARCHIVOS FUENTE ##

SRCS =  $(SRCS_DIR)/ft_add_to_stack.c $(SRCS_DIR)/ft_int_atoi.c $(SRCS_DIR)/ft_push.c \
		$(SRCS_DIR)/ft_lstclear.c $(SRCS_DIR)/ft_split.c $(SRCS_DIR)/ft_swap.c \
		$(PRINTF_DIR)/char_handler.c $(PRINTF_DIR)/ft_puthex.c \
		$(PRINTF_DIR)/pointer_handler.c $(PRINTF_DIR)/ft_printf.c \
		$(PRINTF_DIR)/ft_putdec.c $(PRINTF_DIR)/str_handler.c \
		$(PRINTF_DIR)/Libft_src/ft_itoa.c $(PRINTF_DIR)/Libft_src/ft_strlen.c \
		$(PRINTF_DIR)/Libft_src/ft_putchar_fd.c main_ps.c  ft_treat_args.c \
		$(PRINTF_DIR)/Libft_src/ft_putstr_fd.c $(SRCS_DIR)/ft_free_split.c \
		$(SRCS_DIR)/ft_rotate.c $(SRCS_DIR)/ft_rev_rotate.c \
		$(SRCS_DIR)/ft_add_index.c $(SRCS_DIR)/ft_is_sorted.c \
		$(SRCS_DIR)/ft_small_sort.c $(SRCS_DIR)/ft_radix.c
		 

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g -I. -I$(PRINTF_DIR)

## COMPILAR EJECUTABLE ##

all : $(NAME)

$(NAME) : $(OBJS) Makefile $(HEADRS)
		clang $(CFLAGS) $(OBJS) -o $(NAME)


## COMPILAR OBJETOS ##

%.o: %.c $(HEADRS) Makefile
		clang $(CFLAGS) -c $< -o $@

## PHONYS ##

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)
	
re : fclean all

.PHONY: all clean fclean re
