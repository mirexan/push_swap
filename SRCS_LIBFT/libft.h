/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:33:07 by mregada-          #+#    #+#             */
/*   Updated: 2025/04/07 18:36:50 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "../push_swap.h"

int ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);
char	**ft_split(char const *s, char c);
void	*ft_add_to_stack(t_stack **stack, int num);

#endif
