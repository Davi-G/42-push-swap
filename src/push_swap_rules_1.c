/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagomez <dagomez@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:55:34 by dagomez           #+#    #+#             */
/*   Updated: 2023/01/17 14:55:51 by dagomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sx(t_node	**list)
{
	int	aux_a;

	if (!(*list))
		return ;
	aux_a = (*list)->next->values;
	(*list)->next->values = (*list)->values;
	(*list)->values = aux_a;
}

void	px(t_node	**list_1, t_node	**list_2, char x)
{
	if (!(*list_2))
		return ;
	if (!(*list_2)->fixed)
		return ;
	push_up(list_2, list_1);
	if (x == 'a')
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}

void	rx(t_node	**list)
{
	t_node	*old_first;
	t_node	*old_last;
	t_node	*new_first;

	if (!(*list)->fixed)
		return ;
	old_first = *list;
	old_last = *list;
	while (old_last->next)
		old_last = old_last->next;
	old_last->next = old_first;
	new_first = old_first->next;
	old_first->next = NULL;
	*list = new_first;
}

void	rrx(t_node	**list)
{
	t_node	*old_first;
	t_node	*old_last;
	t_node	*prev;
	t_node	*tmp;

	if (!(*list)->fixed)
		return ;
	old_first = *list;
	old_last = NULL;
	prev = NULL;
	tmp = *list;
	while (tmp->next)
	{
		if (tmp->next->next == NULL)
		{
			prev = tmp;
			old_last = prev->next;
			break ;
		}
		tmp = tmp->next;
	}
	old_last->next = old_first;
	prev->next = NULL;
	*list = old_last;
}
