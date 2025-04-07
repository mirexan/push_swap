/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:28:13 by mregada-          #+#    #+#             */
/*   Updated: 2024/10/14 19:21:56 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		signo;
	int		resultado;

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
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultado = 10 * resultado + (str[i] - '0');
		i++;
	}
	return (resultado * signo);
}
