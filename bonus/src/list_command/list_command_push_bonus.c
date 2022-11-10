/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_command_push_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 03:38:06 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 18:36:12 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

void	push_source_first_to_target(t_list *source_list, t_list *target_list)
{
	t_node	*source_first_node;

	if (is_empty(source_list))
		return ;
	source_first_node = pop_head_side(source_list);
	push_head_side(target_list, source_first_node);
}

void	pa(t_list *list_a, t_list *list_b)
{
	push_source_first_to_target(list_b, list_a);
}

void	pb(t_list *list_a, t_list *list_b)
{
	push_source_first_to_target(list_a, list_b);
}
