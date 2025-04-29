/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:48:36 by mregada-          #+#    #+#             */
/*   Updated: 2025/04/26 18:40:01 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_stack *stack)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	tmp = stack;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

static void	ft_fill_array(t_stack *stack, int *arr)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		arr[i] = tmp->num;
		tmp = tmp->next;
		i++;
	}
}

static void	ft_bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				k = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = k;
			}
			j++;
		}
		i++;
	}
}

void	ft_fill_index(t_stack *stack, int *arr, int size)
{
	t_stack	*tmp;
	int		i;

	tmp = stack;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->num == arr[i])
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

void	ft_add_index(t_stack *stack)
{
	int		size;
	int		*arr;

	size = ft_stack_size(stack);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return ;
	ft_fill_array(stack, arr);
	ft_bubble_sort(arr, size);
	ft_fill_index(stack, arr, size);
	free(arr);
}
