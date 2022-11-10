/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_command_reverse_rotate.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 03:49:51 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 20:00:49 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse_rotate(t_list *list)
{
	t_node	*last_node;

	if (is_empty(list))
		ft_exit("list is empty", STDERR_FILENO, EXIT_FAILURE);
	last_node = pop_tail_side(list);
	push_head_side(list, last_node);
}

void	rra(t_list *list_a)
{
	reverse_rotate(list_a);
	ft_printf("rra\n");
}

void	rrb(t_list *list_b)
{
	reverse_rotate(list_b);
	ft_printf("rrb\n");
}

void	rrr(t_list *list_a, t_list *list_b)
{
	reverse_rotate(list_a);
	reverse_rotate(list_b);
	ft_printf("rrr\n");
}
