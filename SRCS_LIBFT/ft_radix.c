/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 20:04:10 by mregada-          #+#    #+#             */
/*   Updated: 2025/04/20 21:57:10 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_max_bits(t_stack *stack_a)
{
	int	size;
	int max_num;
	int	max_bits;
	
	max_bits = 0;
	size = ft_stack_size(stack_a);
	max_num = size - 1;
	while ((max_num >> max_bits) != 0) //cuando max_bits se desplace los suficiente, max_num
		max_bits++; // deberia quedar a 0
	return (max_bits);
}

void	ft_radix(t_stack **stack_a, t_stack **stack_b)
{
	int	max_bits; 
	int	i;
	int	j;
	
	max_bits = ft_max_bits(t_stack *stack_a);
	i = 0;
	while (i < max_bits)
	{
	}

}
