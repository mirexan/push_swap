/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:47:20 by mregada-          #+#    #+#             */
/*   Updated: 2025/04/16 18:31:49 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	if ((*stack)->next != NULL)
	{
		t_stack	*ptr;
		int t;
		int d;

		t = (*stack)->num;
		ptr = *stack;
		ptr = (*stack)->next;
		d = ptr->num;
		ptr->num = t;
		(*stack)->num = d;
	}
	else
		return;
}

