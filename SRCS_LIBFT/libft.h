/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:33:07 by mregada-          #+#    #+#             */
/*   Updated: 2025/04/25 22:22:11 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
}	t_stack;

int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	ft_add_to_stack(t_stack **stack, int num);
void	ft_lstclear(t_stack **stack);
void	ft_free_split(char **split);
void	ft_swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ft_push(t_stack **taker, t_stack **receiver);
void	pa(t_stack	**stack_b, t_stack **stack_a);
void	pb(t_stack	**stack_a, t_stack **stack_b);
void	ft_rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rev_rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_add_index(t_stack *stack);
int		ft_is_sorted(t_stack *stack_a);
int		ft_stack_size(t_stack *stack);
void	ft_small_sort(t_stack **stack_a, t_stack **stack_b);
void	ft_radix(t_stack **stack_a, t_stack **stack_b);

#endif
