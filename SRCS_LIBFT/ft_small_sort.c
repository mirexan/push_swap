/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:17:12 by mregada-          #+#    #+#             */
/*   Updated: 2025/04/22 22:09:04 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_double_pa_ra(t_stack **stack_a, t_stack **stack_b)
{
	pa(&stack_b, &stack_a);
	ra(&stack_a);
	pa(&stack_b, &stack_a);
	ra(&stack_a);
}

static void	ft_sort_three(t_stack **stack_a)
{
	int	k;
	int	l;
	int	m;
	
	k = (*stack_a)->index;
	l = (*stack_a)->next->index;
	m = (*stack_a)->next->next->index;

	if (k < m && k > l)
		sa(&stack_a);
	else if (k < l && k > m)
		rra(&stack_a);
	else if (k > l && l > m)
	{
		sa(&stack_a);
		rra(&stack_a);
	}
	else if (k > l && l < m)
		ra(&tack_a);
	else if (k < l && l >m)
	{
		rra(&stack_a);
		sa(&stack_a);
	}
}

static void ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int	i;
	int pos;

	tmp = *stack_a;
	i = 0;
	pos = 0;
	while (tmp)
	{
		if (tmp->index == 0)
			pos = i++;
		tmp = tmp->next;
	}
	i = 0;
	if (pos <= 2)
	{
		while (i++ < pos)
			ra(&stack_a);
	else
		while (i++ < 4 - pos)
			rra(stack_a);
	pb(&stack_a, &stack_b);
	ft_sort_three(stack_a);
	pa(&stack_b, &stack_a);
}

static void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	pb(&stack_b);
	pb(&stack_b);
	if (!ft_is_sorted(stack_a))
		ft_sort_three(&stack_a);
	if (ft_is_sorted(stack_b))
		ft_double_pa_ra(&stack_a, &stack_b);
	else 
	{
		sb(&stack_b);
		ft_double_pa_ra(&stack_a, &stack_b);
	}
}

void	ft_small_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	
	size = ft_stack_size(stack_a);
	
	if (size == 2)
		sa(&stack_a);
	else if (size == 3)
		ft_sort_three(&stack_a);
	else if (size == 4)
		ft_sort_four(&stack_a, &stack_b);
	else if (size == 5)
		ft_sort_five(&stack_a, &stack_b);
}
