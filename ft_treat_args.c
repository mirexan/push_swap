/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:49:28 by mregada-          #+#    #+#             */
/*   Updated: 2025/04/18 18:28:36 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_isduplicate(t_stack *stack)
{
	t_stack	*actual;
	t_stack	*check;

	actual = stack;
	while (actual)
	{
		check = actual->next;
		while (check)
		{
			if (check->num == actual->num)
				return (1);
			check = check->next;
		}
		actual = actual->next;
	}
	return (0);
}

static int	ft_fill_from_argv(char **argv, int start, t_stack **stack)
{
	while (argv[start])
	{
		if (!ft_isnum(argv[start]))
			return (0);
		ft_add_to_stack(stack, ft_atoi(argv[start]));
		start++;
	}
	return (1);
}

static int	ft_fill_from_split(char **split, t_stack **stack)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (!ft_isnum(split[i]))
			return (0);
		ft_add_to_stack(stack, ft_atoi(split[i]));
		i++;
	}
	return (1);
}

t_stack	*ft_treat_args(int argc, char *argv[])
{
	t_stack	*stack_a;
	char	**split;

	stack_a = NULL;
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!split || !ft_fill_from_split(split, &stack_a))
		{
			ft_free_split(split);
			return (NULL);
		}
		ft_free_split(split);
	}
	else if (!ft_fill_from_argv(argv, 1, &stack_a))
		return (NULL);
	if (ft_isduplicate(stack_a))
	{
		ft_lstclear (&stack_a);
		return (NULL);
	}
	return (stack_a);
}
