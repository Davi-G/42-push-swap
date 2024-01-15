/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagomez <dagomez@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:36:16 by dagomez           #+#    #+#             */
/*   Updated: 2023/01/17 14:54:29 by dagomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_node **list_a)
{
	t_node	*tmp;

	tmp = *list_a;
	while (tmp && tmp->next)
	{
		if (tmp->values > tmp->next->values)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_3(t_node **list_a)
{
	if ((*list_a)->values > (*list_a)->next->values
		&& (*list_a)->next->values > (*list_a)->next->next->values)
	{
		sx(list_a);
		rrx(list_a);
		ft_printf("sa\nrra\n");
	}
	else if ((*list_a)->values > (*list_a)->next->values
		&& (*list_a)->next->values < (*list_a)->next->next->values
		&& (*list_a)->values > (*list_a)->next->next->values)
	{
		rx(list_a);
		ft_printf("ra\n");
	}
	else if ((*list_a)->values < (*list_a)->next->values
		&& (*list_a)->next->values > (*list_a)->next->next->values
		&& (*list_a)->values < (*list_a)->next->next->values)
	{
		sx(list_a);
		rx(list_a);
		ft_printf("sa\nra\n");
	}
	else
		sort_3_1(list_a);
}

void	sort_3_1(t_node **list_a)
{
	if ((*list_a)->values > (*list_a)->next->values
		&& (*list_a)->next->values < (*list_a)->next->next->values
		&& (*list_a)->values < (*list_a)->next->next->values)
	{
		sx(list_a);
		ft_printf("sa\n");
	}
	else if ((*list_a)->values < (*list_a)->next->values
		&& (*list_a)->next->values > (*list_a)->next->next->values
		&& (*list_a)->values > (*list_a)->next->next->values)
	{
		rrx(list_a);
		ft_printf("rra\n");
	}
}

void	sort_5(t_node **list_a, t_node **list_b)
{
	int	i;

	i = 1;
	while (i < 3)
	{
		if ((*list_a)->fixed == i)
		{
			px(list_b, list_a, 'b');
			i++;
		}
		else
		{
			rx(list_a);
			ft_printf("ra\n");
		}
	}
	if ((*list_b)->fixed < (*list_b)->next->fixed)
	{
		sx(list_b);
		ft_printf("sb\n");
	}
	sort_3(list_a);
	px(list_a, list_b, 'a');
	px(list_a, list_b, 'a');
}

void	sort_small_stack(t_node **list_a, t_node **list_b, int i)
{
	if (is_sort(list_a))
		return ;
	if (i == 3)
		sort_3(list_a);
	else if (i == 5)
		sort_5(list_a, list_b);
	else if (i == 2)
	{
		if ((*list_a)->fixed > (*list_a)->next->fixed)
		{
			sx(list_a);
			ft_printf("sa\n");
		}
	}
}
