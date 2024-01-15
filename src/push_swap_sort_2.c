/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagomez <dagomez@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:16:41 by dagomez           #+#    #+#             */
/*   Updated: 2023/01/17 17:35:09 by dagomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	all_is_different_of_minus1(t_node **list)
{
	t_node	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->fixed == -1)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	get_min_value(t_node **list)
{
	int		index;
	t_node	*tmp;
	t_node	*min;

	index = 1;
	while (!all_is_different_of_minus1(list))
	{
		tmp = *list;
		min = NULL;
		while (tmp)
		{
			if (tmp->fixed == -1)
			{
				if (!min)
					min = tmp;
				else if (tmp->values <= min->values)
					min = tmp;
			}
			tmp = tmp->next;
		}
		min->fixed = index;
		index++;
	}
}

void	radix_sort(t_node **list_a, t_node **list_b)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	size = ft_lstsize_1(*list_a);
	while (!is_sort(list_a))
	{
		j = 0;
		while (j++ < size)
		{
			if ((((*list_a)->fixed >> i) & 1))
			{
				rx(list_a);
				ft_printf("ra\n");
			}
			else
				px(list_b, list_a, 'b');
		}
		while (ft_lstsize_1(*list_b) != 0)
			px(list_a, list_b, 'a');
		i++;
	}
}
