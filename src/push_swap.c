/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagomez <dagomez@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:09:43 by dagomez           #+#    #+#             */
/*   Updated: 2023/01/17 17:36:59 by dagomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **num, t_node **list_a, t_node **list_b)
{
	int		i;

	if (argc > 2)
		if (!check_all(num, argc))
			return ;
	if (argc == 2)
		i = parser_num(num, argc, list_a);
	else
		i = parser_num2(num, argc, list_a);
	get_min_value(list_a);
	if (i == 5 || i == 3 || i == 2)
		sort_small_stack(list_a, list_b, i);
	else
		radix_sort(list_a, list_b);
}

	/* printlist(*list_a, *list_b);
void	printlist(t_node *list_a, t_node *list_b)
{
	int	a;
	int	b;

	ft_printf("\n");
	while (list_a || list_b)
	{
		if (list_a)
		{
			if (list_a)
				a = list_a->values;
			list_a = list_a->next;
		}
		else
			a = 0;
		if (list_b)
		{
			if (list_b)
				b = list_b->values;
			list_b = list_b->next;
		}
		else
			b = 0;
		ft_printf(" %d     %d \n", a, b);
	}
	ft_printf("---------\n A     B \n\n");
}
 */