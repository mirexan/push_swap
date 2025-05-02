/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:17:12 by mregada-          #+#    #+#             */
/*   Updated: 2025/04/26 18:41:14 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push_smaller(t_stack **stack_a, t_stack **stack_b, int i)
{
	t_stack	*tmp;
	int		pos;
	int		j;

	tmp = *stack_a;
	pos = 0;
	j = 0;
	while (tmp)
	{
		if (tmp->index == i)//encuentra el del indice 0 o 1
			break ;
		pos++; // posicion en la que se va a encontrar
		tmp = tmp->next;
	}
	if (pos <= 2) //si posicion esta por arriba
		while (j++ < pos)
			ra(stack_a); // rotamos stack hasta la posicion
	else
		while (j++ < (ft_stack_size(*stack_a) - pos))//para hacer menos mov, rra
			rra(stack_a);
	pb(stack_a, stack_b);// hacemos push
}

static void	ft_sort_three(t_stack **stack_a)
{
	int	k;
	int	l;
	int	m;

	k = (*stack_a)->index;
	l = (*stack_a)->next->index;
	m = (*stack_a)->next->next->index;
	if (k < m && k > l) //movimientos segun indice
		sa(stack_a);
	else if (k < l && k > m)
		rra(stack_a);
	else if (k > l && l > m)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (k > l && l < m)
		ra(stack_a);
	else if (k < l && l > m)
	{
		rra(stack_a);
		sa(stack_a);
	}
}

static void	ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		i;
	int		pos;

	tmp = *stack_a;
	i = 0;
	pos = 0;
	while (tmp)
	{
		if (tmp->index == 0)
			pos = i; //identificamos posicion de indice 0
		i++;
		tmp = tmp->next;
	}
	i = 0;
	if (pos <= 2) //si pos <=2 hacemos ra pos -1(por numeracion) veces
		while (i++ < pos)
			ra(stack_a);
	else
		while (i++ < 4 - pos)
			rra(stack_a);
	pb(stack_a, stack_b); // separamos el indice 0
	ft_sort_three(stack_a); //ordenamos los 3 de stack_a
	pa(stack_b, stack_a); //devolvemos indice 0
}

static void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_smaller(stack_a, stack_b, 0);//primero el de indice 0
	ft_push_smaller(stack_a, stack_b, 1);//asi con pa de vuelta quedan ordenados
	if (!ft_is_sorted(*stack_a))
		ft_sort_three(stack_a); //reutilizamos ft_sort_three
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}

void	ft_small_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_stack_size(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		ft_sort_three(stack_a);
	else if (size == 4)
		ft_sort_four(stack_a, stack_b);
	else if (size == 5)
		ft_sort_five(stack_a, stack_b);
}
