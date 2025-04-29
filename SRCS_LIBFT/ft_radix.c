/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 20:04:10 by mregada-          #+#    #+#             */
/*   Updated: 2025/04/26 19:20:30 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_push_or_rotate(t_stack **stack_a, t_stack **stack_b, int bit)
{
	int	pushed;
	int	size;
	int	j;

	size = ft_stack_size(*stack_a);
	j = 0;
	pushed = 0;
	while (j < size)
	{
		if ((((*stack_a)->index >> bit) & 1) == 0)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		j++;
	}
	return (pushed);
}

static int	ft_all_same_bit(t_stack *stack_a, int bit)
{
	int	reference_bit;

	if (!stack_a)
		return (1);
	reference_bit = (stack_a->index >> bit) & 1;
	while (stack_a)
	{
		if (((stack_a->index >> bit) & 1) != reference_bit)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

static int	ft_max_bits(t_stack *stack_a)
{
	int	max_num;
	int	max_bits;

	max_bits = 0;
	max_num = (ft_stack_size(stack_a)) - 1;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	ft_radix(t_stack **stack_a, t_stack **stack_b)
{
	int	max_bits;
	int	bit;
	int	pushed;

	max_bits = ft_max_bits(*stack_a);
	bit = 0;
	pushed = 0;
	while (bit < max_bits)
	{
		if (ft_all_same_bit(*stack_a, bit))
		{
			bit++;
			continue ;
		}
		pushed = ft_push_or_rotate(stack_a, stack_b, bit);
		while (pushed > 0)
		{
			if (ft_is_sorted(*stack_a) && ft_stack_size(*stack_b) == 0)
				break ;
			pa(stack_b, stack_a);
			pushed--;
			//if ((*stack_a)->next && (*stack_a)->index > (*stack_a)->next->index)
        		//ra(stack_a);
		}
		bit++;
	}
}
