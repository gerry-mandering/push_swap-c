/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_with_greedy_algorithm.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:47:59 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 20:01:02 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	copy_numbers_to_array(int **num_array, t_list *list)
{
	int		i;
	t_node	*current_node;

	i = 0;
	current_node = list->head->next;
	(*num_array) = (int *)ft_calloc((list->size), sizeof(int));
	while (current_node->next != NULL)
	{
		(*num_array)[i++] = current_node->number;
		current_node = current_node->next;
	}
}

void	set_pivot(int *pivot, t_list *list_a)
{
	int	i;
	int	part_size;
	int	remainder;

	i = 0;
	part_size = (list_a->size) / TOTAL_PART;
	remainder = (list_a->size) % TOTAL_PART;
	while (i < PIVOT_COUNT)
	{
		if (i == 0)
			pivot[i] = part_size - 1;
		else
			pivot[i] = pivot[i - 1] + part_size;
		if (remainder != 0)
		{
			pivot[i]++;
			remainder--;
		}
		i++;
	}
}

void	pb_and_rb(t_list *list_a, t_list *list_b)
{
	pb(list_a, list_b);
	rb(list_b);
}

void	divide_list(int *num_array, int *pivot, t_list *list_a, t_list *list_b)
{
	int					circulate_count;
	int					p_index;
	t_circulate_point	circulate_point;

	circulate_count = 0;
	while (circulate_count < (TOTAL_PART / 2))
	{
		circulate_point.last_num = get_last(list_a);
		p_index = circulate_count * 2;
		while (1)
		{
			circulate_point.first_num = get_first(list_a);
			if (circulate_point.first_num <= num_array[pivot[p_index]])
				pb(list_a, list_b);
			else if (circulate_point.first_num <= num_array[pivot[p_index + 1]])
				pb_and_rb(list_a, list_b);
			else
				ra(list_a);
			if (circulate_point.first_num == circulate_point.last_num)
				break ;
		}
		circulate_count++;
	}
	while (list_a->size != 0)
		pb(list_a, list_b);
}

void	sort_with_greedy_algorithm(t_list *list_a, t_list *list_b)
{
	int	*num_array;
	int	pivot[PIVOT_COUNT];

	copy_numbers_to_array(&num_array, list_a);
	sort_array(num_array, list_a->size);
	set_pivot(pivot, list_a);
	divide_list(num_array, pivot, list_a, list_b);
	ft_free(num_array);
	greedy_sort(list_a, list_b);
}
