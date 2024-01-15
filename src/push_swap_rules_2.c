/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagomez <dagomez@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 23:59:22 by dagomez           #+#    #+#             */
/*   Updated: 2023/01/17 14:48:00 by dagomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_node	**list_a, t_node	**list_b)
{
	sx(list_a);
	sx(list_b);
}

void	rr(t_node **list_a, t_node **list_b)
{
	rx(list_a);
	rx(list_b);
}

void	rrr(t_node **list_a, t_node **list_b)
{
	rrx(list_a);
	rrx(list_b);
}

int	len_num(char **nums)
{
	int	i;

	i = 0;
	if (!nums)
		return (0);
	while (nums[i])
		i++;
	return (i);
}
