/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rotate_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:27:07 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 20:01:04 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	count_min_rotate(t_rotate_count *list_a_rotate, \
		t_rotate_count *list_b_rotate)
{
	int	rotation_logic[4];
	int	min_rotate;

	rotation_logic[RA_AND_RB] = \
			get_max2(list_a_rotate->using_rotate, list_b_rotate->using_rotate);
	rotation_logic[RRA_AND_RRB] = \
			get_max2(list_a_rotate->using_reverse_rotate, \
				list_b_rotate->using_reverse_rotate);
	rotation_logic[RA_AND_RRB] = \
			(list_a_rotate->using_rotate + list_b_rotate->using_reverse_rotate);
	rotation_logic[RRA_AND_RB] = \
			(list_a_rotate->using_reverse_rotate + list_b_rotate->using_rotate);
	min_rotate = get_min4(rotation_logic);
	return (min_rotate);
}

int	get_rotate_logic(t_rotate_count *list_a_rotate, \
		t_rotate_count *list_b_rotate)
{
	int	rotation_logic[4];
	int	logic;

	rotation_logic[RA_AND_RB] = \
			get_max2(list_a_rotate->using_rotate, list_b_rotate->using_rotate);
	rotation_logic[RRA_AND_RRB] = \
			get_max2(list_a_rotate->using_reverse_rotate, \
				list_b_rotate->using_reverse_rotate);
	rotation_logic[RA_AND_RRB] = \
			(list_a_rotate->using_rotate + list_b_rotate->using_reverse_rotate);
	rotation_logic[RRA_AND_RB] = \
			(list_a_rotate->using_reverse_rotate + list_b_rotate->using_rotate);
	logic = get_min_index(rotation_logic, 4);
	return (logic);
}

void	calculate_rotate_info(t_rotate_info *rotate_info, \
		t_rotate_count *list_a_rotate, t_rotate_count *list_b_rotate)
{
	rotate_info->logic_using = get_rotate_logic(list_a_rotate, list_b_rotate);
	if (rotate_info->logic_using == RA_AND_RB)
	{
		rotate_info->list_a = list_a_rotate->using_rotate;
		rotate_info->list_b = list_b_rotate->using_rotate;
	}
	else if (rotate_info->logic_using == RA_AND_RRB)
	{
		rotate_info->list_a = list_a_rotate->using_rotate;
		rotate_info->list_b = list_b_rotate->using_reverse_rotate;
	}
	else if (rotate_info->logic_using == RRA_AND_RB)
	{
		rotate_info->list_a = list_a_rotate->using_reverse_rotate;
		rotate_info->list_b = list_b_rotate->using_rotate;
	}
	else if (rotate_info->logic_using == RRA_AND_RRB)
	{
		rotate_info->list_a = list_a_rotate->using_reverse_rotate;
		rotate_info->list_b = list_b_rotate->using_reverse_rotate;
	}
}

void	set_rotate_info(t_rotate_info *rotate_info, \
		t_list *list_a, t_list *list_b)
{
	int				node_index;
	t_node			*current_node;
	t_min_rotate	min_rotate;
	t_rotate_count	list_a_rotate;
	t_rotate_count	list_b_rotate;

	node_index = 0;
	current_node = list_b->head->next;
	while (current_node->next != NULL)
	{
		set_list_b_rotate(&list_b_rotate, node_index, list_b);
		set_list_a_rotate(&list_a_rotate, current_node->number, list_a);
		if ((node_index == 0) || \
	(min_rotate.count > count_min_rotate(&list_a_rotate, &list_b_rotate)) || \
	((min_rotate.count == count_min_rotate(&list_a_rotate, &list_b_rotate)) && \
	(current_node->number > min_rotate.number)))
		{
			min_rotate.number = current_node->number;
			min_rotate.count = count_min_rotate(&list_a_rotate, &list_b_rotate);
			calculate_rotate_info(rotate_info, &list_a_rotate, &list_b_rotate);
		}
		current_node = current_node->next;
		node_index++;
	}
}
