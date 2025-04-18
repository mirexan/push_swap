/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:15:28 by mregada-          #+#    #+#             */
/*   Updated: 2025/04/18 18:38:43 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
