/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:28:13 by mregada-          #+#    #+#             */
/*   Updated: 2025/04/26 18:43:21 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_result(const char *str, size_t i)
{
	long	resultado;

	resultado = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultado = 10 * resultado + (str[i] - '0');
		i++;
	}
	return (resultado);
}

long	ft_int_atoi(const char *str)
{
	size_t	i;
	int		signo;
	long	resultado;

	i = 0;
	signo = 1;
	resultado = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		signo = -1;
		i++;
	}
	resultado = ft_result(str, i);
	return (resultado * signo);
}
