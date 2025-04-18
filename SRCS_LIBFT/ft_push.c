/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:48:37 by mregada-          #+#    #+#             */
/*   Updated: 2025/04/18 18:44:25 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstadd_front(t_stack **taker, t_stack *new)
{
	if (!taker || !new)
		return ;
	new->next = *taker;
	*taker = new;
}

void	ft_push(t_stack **taker, t_stack **giver)
{
	t_stack	*newnode;

	if (*giver)
	{
		newnode = *giver;
		*giver = (*giver)->next;
		ft_lstadd_front(taker, newnode);
	}
}
