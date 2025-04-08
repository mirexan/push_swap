/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:06:30 by mregada-          #+#    #+#             */
/*   Updated: 2024/11/14 19:34:21 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>

int		ft_printf(char const *str, ...);
int		char_handler(va_list args);
int		str_handler(va_list args);
int		pointer_handler(va_list args);
int		ft_puthex(char format, va_list args);
int		ft_putdec(char format, va_list args);
int		ft_strlen(const char *str);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
char	*ft_itoa(int n);

#endif
