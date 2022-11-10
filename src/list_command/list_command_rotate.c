/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_command_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 03:44:55 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 20:00:46 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate(t_list *list)
{
	t_node	*first_node;

	if (is_empty(list))
		ft_exit("list is empty", STDERR_FILENO, EXIT_FAILURE);
	first_node = pop_head_side(list);
	push_tail_side(list, first_node);
}

void	ra(t_list *list_a)
{
	rotate(list_a);
	ft_printf("ra\n");
}

void	rb(t_list *list_b)
{
	rotate(list_b);
	ft_printf("rb\n");
}

void	rr(t_list *list_a, t_list *list_b)
{
	rotate(list_a);
	rotate(list_b);
	ft_printf("rr\n");
}
