/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:18:42 by mregada-          #+#    #+#             */
/*   Updated: 2024/10/15 18:38:30 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	cont_digit(long n)
{
	int	c;

	c = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

static char	*asignar_num(long num, int flag, int unidades, char *resultado)
{
	while (unidades > 0)
	{
		resultado[unidades + flag - 1] = (num % 10) + '0';
		num = num / 10;
		unidades--;
	}
	return (resultado);
}

char	*ft_itoa(int n)
{
	char	*resultado;
	int		unidades;
	int		flag;
	long	num;

	flag = 0;
	num = n;
	if (num < 0)
	{
		flag = 1;
		num = num * -1;
	}
	unidades = cont_digit(num);
	resultado = (char *)malloc((unidades + flag + 1) * sizeof(char));
	if (resultado == NULL)
		return (NULL);
	resultado [unidades + flag] = '\0';
	resultado = asignar_num(num, flag, unidades, resultado);
	if (flag == 1)
		resultado[0] = '-';
	return (resultado);
}
