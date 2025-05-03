/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 20:04:10 by mregada-          #+#    #+#             */
/*   Updated: 2025/05/03 12:17:23 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_push_or_rotate(t_stack **stack_a, t_stack **stack_b, int bit)
{
	int	size;
	int	j;
	int	pushed;

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
	while (bit < max_bits)
	{
		pushed = 0;
		pushed = ft_push_or_rotate(stack_a, stack_b, bit);
		while (pushed--)
			pa(stack_b, stack_a);
		bit++;
	}
}
