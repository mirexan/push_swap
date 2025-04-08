/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:53:55 by mregada-          #+#    #+#             */
/*   Updated: 2025/04/08 21:12:44 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{	
	if (argc < 2)
		return (0);
	else if (argc == 2 && argv[1][1] != '\0')
	{
		ft_split(argv[1], ' ');
	}
	int	i;
	t_stack	*stack_a;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		ft_add_to_stack(&stack_a, ft_atoi(argv[i]));
		ft_printf("anadido numero %d\n", ft_atoi(argv[i]));
		i++;
	}
	ft_printf("contenido del stack\n");
	t_stack	*actual = stack_a;
	i = 1;
	while(actual)
	{
		ft_printf("Posicion %d: %d\n", i, actual->num);
		actual = actual->next;
		i++;
	}
	ft_lstclear(&stack_a);
	return (0);
}

