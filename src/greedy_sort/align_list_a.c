/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_list_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:17:18 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 19:59:34 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_min_number_index(t_list *list_a)
{
	int		node_index;
	int		min_number;
	int		min_number_index;
	t_node	*current_node;

	node_index = 0;
	current_node = list_a->head->next;
	while (current_node->next != NULL)
	{
		if ((node_index == 0) || current_node->number < min_number)
		{
			min_number = current_node->number;
			min_number_index = node_index;
		}
		current_node = current_node->next;
		node_index++;
	}
	return (min_number_index);
}

t_rotate_count	get_list_a_align(int min_number_index, t_list *list_a)
{
	t_rotate_count	list_a_align;

	if (min_number_index == 0)
	{
		list_a_align.using_rotate = 0;
		list_a_align.using_reverse_rotate = 0;
	}
	else
	{
		list_a_align.using_rotate = min_number_index;
		list_a_align.using_reverse_rotate = (list_a->size) - min_number_index;
	}
	return (list_a_align);
}

int	get_align_logic(int using_rotate, int using_reverse_rotate)
{
	if (using_rotate < using_reverse_rotate)
		return (RA);
	else
		return (RRA);
}

void	align_list_a(t_list *list_a)
{
	int				min_number_index;
	int				logic;
	t_rotate_count	list_a_align;

	min_number_index = get_min_number_index(list_a);
	list_a_align = get_list_a_align(min_number_index, list_a);
	logic = get_align_logic(list_a_align.using_rotate, \
			list_a_align.using_reverse_rotate);
	if (logic == RA)
	{
		while (list_a_align.using_rotate != 0)
		{
			ra(list_a);
			(list_a_align.using_rotate)--;
		}
	}
	else
	{
		while (list_a_align.using_reverse_rotate != 0)
		{
			rra(list_a);
			(list_a_align.using_reverse_rotate)--;
		}
	}
}
