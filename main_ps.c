/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:53:55 by mregada-          #+#    #+#             */
/*   Updated: 2025/04/20 21:34:58 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_printstack(t_stack *stack)
{
	t_stack	*actual;
	int		i;

	actual = stack;
	i = 1;
	while (actual)
	{
		ft_printf("Num: %d Indice: %d\n", actual->num, actual->index);
		actual = actual->next;
		i++;
	}
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
		ft_printf("Error\n");
		return (1);
	}
	ft_add_index(stack_a);
	ft_printstack(stack_a);
	if (ft_is_sorted(stack_a))
			ft_printf("already sorted, no moves needed\n");
	ft_printf("stack size is %d\n", ft_stack_size(stack_a));
	//ft_swap(&stack_a);
	//ft_push(&stack_b, &stack_a);
	/*ft_rev_rotate(&stack_a);
	ft_printf("El stack a es :\n");
	ft_printstack(stack_a);
	ft_printf("El stack b es :\n");
	ft_printstack(stack_b);*/
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
