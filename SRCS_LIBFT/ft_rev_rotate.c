/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:15:28 by mregada-          #+#    #+#             */
/*   Updated: 2025/04/22 19:56:01 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a)
{
	ft_rev_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	ft_rev_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
	ft_printf("rrr\n");
}

void	ft_rev_rotate(t_stack **stack)
{
	t_stack	*firstnode;
	t_stack	*iter;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	iter = *stack;
	while (iter->next->next)//iteramos hasta el penultimo
		iter = iter->next;
	firstnode = iter->next;//guardamos el ultimo en el futuro primero
	iter->next = NULL;// cortamos el enlace del ultimo nodo par ano generar bucle
	firstnode->next = *stack; //enlazamos la primera posicion
	*stack = firstnode;// situamos primera posicion en stack original
}
