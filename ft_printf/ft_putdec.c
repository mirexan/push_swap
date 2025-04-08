/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:18:44 by mregada-          #+#    #+#             */
/*   Updated: 2024/11/14 19:18:42 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	counter(unsigned int unum)
{
	int	len;

	len = 0;
	if (unum == 0)
		return (1);
	while (unum != 0)
	{
		unum = (unum / 10);
		len++;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int unum)
{
	char	*resultado;
	int		len;

	len = counter(unum);
	resultado = (char *)malloc((len + 1) * sizeof(char));
	if (resultado == NULL)
		return (NULL);
	resultado[len] = '\0';
	while (len > 0)
	{
		len--;
		resultado[len] = (unum % 10) + '0';
		unum = (unum / 10);
	}
	return (resultado);
}

int	ft_putdec(char format, va_list args)
{
	int				len;
	int				num;
	unsigned int	unum;
	char			*str;

	num = 0;
	if (format == 'd' || format == 'i')
	{
		num = va_arg(args, int);
		str = ft_itoa(num);
	}
	if (format == 'u')
	{
		unum = va_arg(args, unsigned int);
		str = ft_uitoa(unum);
	}
	len = ft_strlen(str);
	if (ft_putstr_fd(str, 1) == -1)
		return (-1);
	free (str);
	return (len);
}
