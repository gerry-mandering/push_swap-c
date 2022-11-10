/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_command_rotate_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 03:44:55 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 18:36:20 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

void	rotate(t_list *list)
{
	t_node	*first_node;

	if (is_empty(list))
		return ;
	first_node = pop_head_side(list);
	push_tail_side(list, first_node);
}

void	ra(t_list *list_a, t_list *list_b)
{
	(void)list_b;
	rotate(list_a);
}

void	rb(t_list *list_a, t_list *list_b)
{
	(void)list_a;
	rotate(list_b);
}

void	rr(t_list *list_a, t_list *list_b)
{
	rotate(list_a);
	rotate(list_b);
}
