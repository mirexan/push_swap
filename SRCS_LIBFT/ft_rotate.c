/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:46:33 by mregada-          #+#    #+#             */
/*   Updated: 2025/04/26 18:38:24 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a)
{
	ft_rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack **stack_b)
{
	ft_rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("rr\n");
}

void	ft_rotate(t_stack **stack)
{
	t_stack	*lastnode;
	t_stack	*iter;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	lastnode = *stack;
	*stack = (*stack)->next;
	iter = *stack;
	while (iter->next)
		iter = iter->next;
	iter->next = lastnode;
	lastnode->next = NULL;
}
