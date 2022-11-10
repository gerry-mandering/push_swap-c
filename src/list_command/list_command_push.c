/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_command_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 03:38:06 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 20:00:51 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_source_first_to_target(t_list *source_list, t_list *target_list)
{
	t_node	*source_first_node;

	if (is_empty(source_list))
		return ;
	source_first_node = pop_head_side(source_list);
	push_head_side(target_list, source_first_node);
}

void	pa(t_list *list_b, t_list *list_a)
{
	push_source_first_to_target(list_b, list_a);
	ft_printf("pa\n");
}

void	pb(t_list *list_a, t_list *list_b)
{
	push_source_first_to_target(list_a, list_b);
	ft_printf("pb\n");
}
