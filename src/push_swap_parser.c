/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagomez <dagomez@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:34:40 by dagomez           #+#    #+#             */
/*   Updated: 2023/01/17 17:56:45 by dagomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	len_stack(t_node **list)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = *list;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	parser_num2(char **argv, int argc, t_node **list_a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		push(ft_atoi(argv[i]), list_a);
		i++;
	}
	return (i - 1);
}

int	parser_num(char **argv, int argc, t_node **list_a)
{
	char	**num;
	int		i;
	int		index;

	index = 1;
	while (index < argc)
	{
		if (is_space(argv[index]))
		{
			num = ft_split(argv[index], ' ');
			check_all_2(num);
			i = 0;
			while (i <= len_num(num) - 1)
			{
				push(ft_atoi(num[i]), list_a);
				free(num[i]);
				i++;
			}
			free(num);
		}
		index++;
	}
	i = len_stack(list_a);
	return (i);
}
