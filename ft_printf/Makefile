# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregada- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 15:00:32 by mregada-          #+#    #+#              #
#    Updated: 2024/11/29 20:41:41 by mregada-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME = libftprintf.a
HEADRS = ft_printf.h
LIBFT_DIR = Libft_src

# Archivos fuente

SRCS = char_handler.c str_handler.c pointer_handler.c ft_printf.c \
	ft_puthex.c ft_putdec.c $(LIBFT_DIR)/ft_strlen.c $(LIBFT_DIR)/ft_putchar_fd.c \
	$(LIBFT_DIR)/ft_itoa.c $(LIBFT_DIR)/ft_putstr_fd.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I $(HEADRS)

# Reglas

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

# compilar prueba

#prueba: $(NAME)  main_printf.c
	#cc $(CFLAGS) main_printf.c $(NAME) -o prueba

# Compilar archivos de directorio

%.o: %.c $(HEADRS) Makefile
	cc $(CFLAGS) -c $< -o $@

# Phonys

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
