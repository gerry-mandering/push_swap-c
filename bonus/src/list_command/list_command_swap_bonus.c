/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_command_swap_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 03:30:06 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 18:36:23 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

void	swap_first_second(t_list *list)
{
	t_node	*first_node;
	t_node	*second_node;

	if (list->size < 2)
		return ;
	first_node = pop_head_side(list);
	second_node = pop_head_side(list);
	push_head_side(list, first_node);
	push_head_side(list, second_node);
}

void	sa(t_list *list_a, t_list *list_b)
{
	(void)list_b;
	swap_first_second(list_a);
}

void	sb(t_list *list_a, t_list *list_b)
{
	(void)list_a;
	swap_first_second(list_b);
}

void	ss(t_list *list_a, t_list *list_b)
{
	swap_first_second(list_a);
	swap_first_second(list_b);
}
