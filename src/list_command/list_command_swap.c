/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_command_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 03:30:06 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 20:00:44 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap_first_second(t_list *list)
{
	t_node	*first_node;
	t_node	*second_node;

	if (list->size < 2)
		ft_exit("lacking list size", STDERR_FILENO, EXIT_FAILURE);
	first_node = pop_head_side(list);
	second_node = pop_head_side(list);
	push_head_side(list, first_node);
	push_head_side(list, second_node);
}

void	sa(t_list *list_a)
{
	swap_first_second(list_a);
	ft_printf("sa\n");
}

void	sb(t_list *list_b)
{
	swap_first_second(list_b);
	ft_printf("sb\n");
}

void	ss(t_list *list_a, t_list *list_b)
{
	swap_first_second(list_a);
	swap_first_second(list_b);
	ft_printf("ss\n");
}
