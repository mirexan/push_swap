/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:11:33 by mregada-          #+#    #+#             */
/*   Updated: 2025/04/26 18:44:22 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_add_to_stack(t_stack **stack, int num)
{
	t_stack	*newnode;
	t_stack	*last_node;

	newnode = (t_stack *)malloc(sizeof(t_stack));
	if (!newnode)
		return ;
	newnode->num = num;
	newnode->next = NULL;
	if (*stack == NULL)
		*stack = newnode;
	else
	{
		last_node = *stack;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = newnode;
	}
}
