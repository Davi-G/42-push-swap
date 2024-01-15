/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagomez <dagomez@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:07:21 by dagomez           #+#    #+#             */
/*   Updated: 2023/01/17 18:28:46 by dagomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

void	push(int num, t_node **list_a)
{
	t_node	*new;
	t_node	*aux;

	new = ft_calloc(sizeof(t_node), 1);
	new->fixed = -1;
	new->values = num;
	new->next = NULL;
	if (!*list_a)
		*list_a = new;
	else
	{
		aux = *list_a;
		while (aux->next)
			aux = aux->next;
		aux->next = new;
		new = NULL;
	}
	aux = NULL;
}

void	push_up(t_node **list_1, t_node **list_2)
{
	t_node	*aux;
	t_node	*tmp;

	aux = *list_1;
	tmp = *list_2;
	*list_2 = aux;
	*list_1 = (*list_1)->next;
	aux->next = tmp;
}

int	ft_lstsize_1(t_node *lst)
{
	t_node	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	check_duplicate_2(int num, char **num_aux, int i)
{
	i++;
	while (num_aux[i])
	{
		if (num == ft_atoi(num_aux[i]))
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}
