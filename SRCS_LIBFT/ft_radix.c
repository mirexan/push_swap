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
	while (j < size) //recorrer todo stack
	{
		if ((((*stack_a)->index >> bit) & 1) == 0) //si lsb es 0, enviamos a stack_b
		{
			pb(stack_a, stack_b);
			pushed++; //sumamos contador para devolver luego
		}
		else
			ra(stack_a);
		j++;
	}
	return (pushed);
}

static int	ft_all_same_bit(t_stack *stack_a, int bit) //para reducir movimientos
{
	int	reference_bit;

	if (!stack_a)
		return (1);
	reference_bit = (stack_a->index >> bit) & 1; // primer bit actual, si es 1 o 0
	while (stack_a)
	{
		if (((stack_a->index >> bit) & 1) != reference_bit)
			return (0); // si no es igual que referencia cortamos
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
	while ((max_num >> max_bits) != 0) // cuando maxbits haga que max_num desplazado
		max_bits++;// llegue a 0, sera por que habremos llegado al num mas grande
	return (max_bits); // y tendremos los bits necesarios para representarlo
}

void	ft_radix(t_stack **stack_a, t_stack **stack_b)
{
	int	max_bits;
	int	bit;
	int	pushed;

	max_bits = ft_max_bits(*stack_a);//maximo de bits que habrá
	bit = 0;
	pushed = 0;
	while (bit < max_bits)
	{
		if (ft_all_same_bit(*stack_a, bit)) //si todo el stack tiene el mismo
		{
			bit++;//ahorramos movimientos pb y ra, avanzando al siguiente bit
			continue ; //salta iteracion actual y pasa al siguiente bucle
		}
		pushed = ft_push_or_rotate(stack_a, stack_b, bit);
		while (pushed > 0)//devolver a stack_a todos los stack_b
		{
			if (ft_is_sorted(*stack_a) && ft_stack_size(*stack_b) == 0)
				break ;
			pa(stack_b, stack_a);
			pushed--;
		}
		bit++;
	}
}
