/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 20:48:34 by mregada-          #+#    #+#             */
/*   Updated: 2025/04/20 21:08:10 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *stack_a)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stack_a;
	while (tmp)
	{
		if (tmp->index != i)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}
