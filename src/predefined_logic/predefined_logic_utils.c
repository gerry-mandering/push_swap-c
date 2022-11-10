/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predefined_logic_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 21:43:10 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 20:00:32 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_list_shape(int *num_array)
{
	int	shape;

	if (get_max_index(num_array, 3) == 0)
	{
		if (get_min_index(num_array, 3) == 1)
			shape = MAX_MIN_MID;
		else
			shape = MAX_MID_MIN;
	}
	else if (get_max_index(num_array, 3) == 1)
	{
		if (get_min_index(num_array, 3) == 0)
			shape = MIN_MAX_MID;
		else
			shape = MID_MAX_MIN;
	}
	else
	{
		if (get_min_index(num_array, 3) == 0)
			shape = MIN_MID_MAX;
		else
			shape = MID_MIN_MAX;
	}
	return (shape);
}

int	get_index(int selected_number, t_list *list_a)
{
	int		node_index;
	t_node	*current_node;

	node_index = 0;
	current_node = list_a->head->next;
	while (current_node->next != NULL)
	{
		if (current_node->number == selected_number)
			return (node_index);
		current_node = current_node->next;
		node_index++;
	}
	return (node_index);
}

void	push_two_min_numbers_to_list_b(t_list *list_a, t_list *list_b)
{
	int	i;
	int	pb_count;
	int	*num_array;
	int	min_numbers_index[2];

	i = 0;
	pb_count = 0;
	copy_numbers_to_array(&num_array, list_a);
	sort_array(num_array, list_a->size);
	min_numbers_index[0] = get_index(num_array[0], list_a);
	min_numbers_index[1] = get_index(num_array[1], list_a);
	while (pb_count < 2)
	{
		if ((i == min_numbers_index[0]) || (i == min_numbers_index[1]))
		{
			pb(list_a, list_b);
			pb_count++;
		}
		else
			ra(list_a);
		i++;
	}
	ft_free(num_array);
}
