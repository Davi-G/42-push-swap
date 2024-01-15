/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagomez <dagomez@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:55:43 by dagomez           #+#    #+#             */
/*   Updated: 2023/01/17 18:31:54 by dagomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_node
{
	int				values;
	int				fixed;
	struct s_node	*next;
}	t_node;

void	push_swap(int argc, char **num, t_node **list_a, t_node **list_b);
int		check_all(char	**num, int j);
int		check_all_2(char **num);
int		check_duplicate(char **num);
int		check_duplicate_2(int num, char **num_aux, int i);
int		check_maxmin(char *num);
int		check_nums(char *num);
void	push(int num, t_node **list_a);
void	push_up(t_node **list_1, t_node **list_2);
void	printlist(t_node *list_a, t_node *list_b);
void	sx(t_node	**list);
void	ss(t_node	**list_a, t_node	**list_b);
void	px(t_node	**list_1, t_node	**list_2, char x);
void	rx(t_node	**list);
void	rr(t_node **list_a, t_node **list_b);
void	rrx(t_node	**list);
void	rrr(t_node **list_a, t_node **list_b);
int		is_sort(t_node **list_a);
void	sort_3(t_node **list_a);
void	sort_3_1(t_node **list_a);
void	sort_5(t_node **list_a, t_node **list_b);
void	sort_small_stack(t_node **list_a, t_node **list_b, int i);
void	radix_sort(t_node **list_a, t_node **list_b);
int		all_is_different_of_minus1(t_node **list);
void	get_min_value(t_node **list);
int		ft_lstsize_1(t_node *lst);
int		parser_num(char **argv, int argc, t_node **list_a);
int		parser_num2(char **argv, int argc, t_node **list_a);
int		is_space(char *str);
int		len_stack(t_node **list);
int		len_num(char **nums);
void	clear_elements(t_node **a);

#endif