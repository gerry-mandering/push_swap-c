/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_list_a_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:18:46 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 20:01:09 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_diff_abs(int num_a, int num_b)
{
	if (num_a > num_b)
		return (num_a - num_b);
	else
		return (num_b - num_a);
}

t_number_info	get_closest_number_info(int selected_number, t_list *list_a)
{
	int				node_index;
	int				diff_abs;
	int				min_diff_abs;
	t_node			*current_node;
	t_number_info	closest_number_info;

	node_index = 0;
	min_diff_abs = 0;
	current_node = list_a->head->next;
	while (current_node->next != NULL)
	{
		diff_abs = get_diff_abs(selected_number, current_node->number);
		if ((node_index == 0) || (diff_abs < min_diff_abs))
		{
			min_diff_abs = diff_abs;
			closest_number_info.number = current_node->number;
			closest_number_info.index = node_index;
		}
		current_node = current_node->next;
		node_index++;
	}
	return (closest_number_info);
}

void	set_closest_number_to_top(t_rotate_count *list_a_rotate, \
		int number_index, t_list *list_a)
{
	if (number_index == 0)
	{
		list_a_rotate->using_rotate = 0;
		list_a_rotate->using_reverse_rotate = 0;
	}
	else
	{
		list_a_rotate->using_rotate = number_index;
		list_a_rotate->using_reverse_rotate = (list_a->size) - number_index;
	}
}

void	set_closest_number_to_bottom(t_rotate_count *list_a_rotate, \
		int number_index, t_list *list_a)
{
	if (number_index == (list_a->size - 1))
	{
		list_a_rotate->using_rotate = 0;
		list_a_rotate->using_reverse_rotate = 0;
	}
	else
	{
		list_a_rotate->using_rotate = number_index + 1;
		list_a_rotate->using_reverse_rotate = \
					((list_a->size) - (number_index + 1));
	}
}

void	set_list_a_rotate(t_rotate_count *list_a_rotate, \
		int selected_number, t_list *list_a)
{
	t_number_info	closest_number_info;

	if (is_empty(list_a))
	{
		list_a_rotate->using_rotate = 0;
		list_a_rotate->using_reverse_rotate = 0;
		return ;
	}
	closest_number_info = get_closest_number_info(selected_number, list_a);
	if (closest_number_info.number > selected_number)
		set_closest_number_to_top(list_a_rotate, \
				closest_number_info.index, list_a);
	else
		set_closest_number_to_bottom(list_a_rotate, \
				closest_number_info.index, list_a);
}
