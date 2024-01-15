/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagomez <dagomez@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:41:37 by dagomez           #+#    #+#             */
/*   Updated: 2023/01/17 18:39:27 by dagomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_num(char *num)
{
	int	i;

	i = 0;
	if (!num)
	{
		ft_printf("Error\n");
		return (0);
	}
	if ((num[i] == '+' || num[i] == '-') && (num + 1) != NULL)
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_duplicate(char **num)
{
	int	i;
	int	j;

	i = 0;
	while (num[i])
	{
		j = i + 1;
		while (num[j])
		{
			if (ft_atoi(num[i]) == ft_atoi(num[j]))
			{
				ft_printf("Error\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_maxmin(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (ft_atoi(num) > 2147483647 || ft_atoi(num) < -2147483648)
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}	
	return (1);
}

int	check_all(char **num, int j)
{
	int	i;

	i = 1;
	while (i < j)
	{
		if (!check_duplicate_2(ft_atoi(num[i]), num, i))
			return (0);
		i++;
	}
	i = 1;
	while (i < j)
	{
		if (!check_num(num[i]))
			return (0);
		i++;
	}
	i = 1;
	while (i < j)
	{
		if (!check_maxmin(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_all_2(char **num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (!check_num(num[i]))
			exit(1);
		i++;
	}
	i = 0;
	while (num[i])
	{
		if (!check_duplicate(num))
			exit(1);
		i++;
	}
	i = 0;
	while (num[i])
	{
		if (!check_maxmin(num[i]))
			exit(1);
		i++;
	}
	return (1);
}
