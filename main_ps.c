/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:53:55 by mregada-          #+#    #+#             */
/*   Updated: 2025/04/29 19:19:53 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_clear_all(t_stack **stack_a, t_stack **stack_b)
{
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (argc < 2)
		return (0);
	stack_a = ft_treat_args(argc, argv);
	if (!stack_a)
	{
		ft_putstr_fd("Error\n", 2);
		ft_clear_all(&stack_a, &stack_b);
		return (1);
	}
	ft_add_index(stack_a);
	if (ft_is_sorted(stack_a))
		return (0);
	if (ft_stack_size(stack_a) <= 5)
		ft_small_sort(&stack_a, &stack_b);
	else
		ft_radix(&stack_a, &stack_b);
	ft_clear_all(&stack_a, &stack_b);
	return (0);
}
