/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:26:29 by mregada-          #+#    #+#             */
/*   Updated: 2024/11/14 19:42:59 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "../ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	len;
	int	i;

	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		if ((write (fd, &s[i], 1)) == -1)
			return (-1);
		i++;
	}
	return (0);
}
