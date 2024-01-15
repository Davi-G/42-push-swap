/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagomez <dagomez@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:13:59 by dagomez           #+#    #+#             */
/*   Updated: 2023/01/17 15:14:04 by dagomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_void(void)
{
	system("leaks -q push_swap");
}

void	clear_elements(t_node **a)
{
	t_node	*tmp;

	tmp = NULL;
	if (*a)
	{
		while (*a)
		{
			tmp = (*a)->next;
			free(*a);
			*a = NULL;
			(*a) = tmp;
		}
		free(*a);
		*a = NULL;
	}
}

int	main(int argc, char **argv)
{
	t_node	*list_a;
	t_node	*list_b;

	list_a = NULL;
	list_b = NULL;
	push_swap(argc, argv, &list_a, &list_b);
	clear_elements(&list_a);
	return (0);
}
	//atexit(ft_void);
