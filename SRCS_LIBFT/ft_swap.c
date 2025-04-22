/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:47:20 by mregada-          #+#    #+#             */
/*   Updated: 2025/04/22 19:36:16 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a)
{
	ft_swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	ft_swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_printf("ss\n");
}

void	ft_swap(t_stack **stack)
{
	t_stack	*ptr;
	int		t;
	int		d;

	if (!*stack || !(*stack)->next)
		return ;
	else
	{
		t = (*stack)->num;
		ptr = *stack;
		ptr = ptr->next;
		d = ptr->num;
		ptr->num = t;
		(*stack)->num = d;
	}
}
