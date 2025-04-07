/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:47:28 by mregada-          #+#    #+#             */
/*   Updated: 2024/10/16 18:39:52 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*conversor(long num, int flag, size_t i, char *str)
{
	while (i > 0)
	{
		str[i + flag - 1] = (num % 10) + '0';
		num = num / 10;
		i--;
	}
	if (flag == 1)
		str[0] = '-';
	return (str);
}

static int	cont_digit(long num)
{
	int	c;

	c = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		num = -num;
	while (num > 0)
	{
		num = num / 10;
		c++;
	}
	return (c);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	str[12];
	size_t	i;
	int		flag;
	long	num;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	flag = 0;
	num = n;
	if (num < 0)
	{
		flag = 1;
		num = -num;
	}
	i = cont_digit(num);
	str[i + flag] = '\0';
	conversor(num, flag, i, str);
	ft_putstr_fd(str, fd);
}
