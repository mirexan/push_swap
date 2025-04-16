/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:33:07 by mregada-          #+#    #+#             */
/*   Updated: 2025/04/16 21:23:49 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>


typedef struct s_stack
{
	int	num;
	struct s_stack	*next;
}	t_stack;

int ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	ft_add_to_stack(t_stack **stack, int num);
void	ft_lstclear(t_stack **stack);
void	ft_free_split(char **split);
void	ft_swap(t_stack **stack);
void	ft_push(t_stack **taker, t_stack **giver);
void	ft_rotate(t_stack **stack);
void	ft_rev_rotate(t_stack **stack);

#endif
