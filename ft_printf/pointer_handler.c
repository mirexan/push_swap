/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:49:36 by mregada-          #+#    #+#             */
/*   Updated: 2024/11/05 19:59:09 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conversor_hex(unsigned long num)
{
	char	*hex;
	int		len;

	hex = "0123456789abcdef";
	len = 0;
	if (num >= 16)
		len += conversor_hex(num / 16);
	ft_putchar_fd(hex[num % 16], 1);
	len++;
	return (len);
}

int	pointer_handler(va_list args)
{
	void	*ptr;
	int		len;

	ptr = va_arg(args, void *);
	if (ptr == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	len = 2;
	len += conversor_hex((unsigned long)ptr);
	return (len);
}
