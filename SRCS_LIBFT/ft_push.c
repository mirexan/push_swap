/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:48:37 by mregada-          #+#    #+#             */
/*   Updated: 2025/04/22 19:28:21 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	ft_push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_printf("pb\n");
}

void	ft_push(t_stack **taker, t_stack **receiver)
{
	t_stack	*newnode;

	if (!*taker)
		return;
	newnode = *taker; //nos llevamos el nodo a mandar
	*taker = (*taker)->next; // situamos el siguiente nodo del stack como primero
	newnode->next = *receiver; // el segundo nodo sera el primero del stack receptor
	*receiver = newnode; // el primer nodo pasa a ser el nodo a mandar
}
