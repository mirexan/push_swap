/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:11:33 by mregada-          #+#    #+#             */
/*   Updated: 2025/04/07 18:03:49 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_add_to_stack(t_stack **stack, int num)
{
	t_stack	*newnode;
	
	newnode = (t_stack *)malloc(sizeof(t_stack))
	if (!newnode)
		return (NULL);
	newnode->num = num;
	newnode->next = NULL; //para que sea el utlimo nodo
	
	if (*stack == NULL) // si esta vacio
		*stack = newnode; //sera el primer nodo
	else //sino, hacemos que recorra la lista 
	{
		t_stack	*last_node;
		
		last_node = *stack;// situamos last_node en el primer nodo de la pila
		while (last_node->next != NULL)// y la recorremos hasta el ultimo nodo
			last_node = last_node->next//cuando senyale a NULL y sea el ultimo
		last_node = newnode; //asignamos el newnode creado al stack apuntado
	} 
	return (newnode);
}
