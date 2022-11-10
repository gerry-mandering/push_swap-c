/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_with_predefined_logic.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:57:43 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 20:00:34 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	predefined_sort_logic_size2(t_list *list, int list_name)
{
	if (get_first(list) < get_last(list))
		return ;
	if (list_name == LIST_A)
		sa(list);
	else
		sb(list);
}

void	predefined_reverse_sort_logic_size2(t_list *list, int list_name)
{
	if (get_first(list) > get_last(list))
		return ;
	if (list_name == LIST_A)
		sa(list);
	else
		sb(list);
}

void	predefined_sort_logic_size3(t_list *list)
{
	int	list_shape;
	int	*num_array;

	copy_numbers_to_array(&num_array, list);
	list_shape = get_list_shape(num_array);
	if (list_shape == MAX_MID_MIN)
	{
		ra(list);
		sa(list);
	}
	else if (list_shape == MAX_MIN_MID)
		ra(list);
	else if (list_shape == MIN_MID_MAX)
		;
	else if (list_shape == MIN_MAX_MID)
	{
		rra(list);
		sa(list);
	}
	else if (list_shape == MID_MAX_MIN)
		rra(list);
	else if (list_shape == MID_MIN_MAX)
		sa(list);
	ft_free(num_array);
}

void	predefined_sort_logic_size4_5(t_list *list_a, t_list *list_b)
{
	push_two_min_numbers_to_list_b(list_a, list_b);
	predefined_reverse_sort_logic_size2(list_b, LIST_B);
	if (list_a->size == 2)
		predefined_sort_logic_size2(list_a, LIST_A);
	else
		predefined_sort_logic_size3(list_a);
	while (list_b->size != 0)
		pa(list_b, list_a);
}

void	sort_with_predefined_logic(t_list *list_a, t_list *list_b)
{
	if (list_a->size == 1)
		ft_exit(NULL, STDOUT_FILENO, EXIT_SUCCESS);
	else if (list_a->size == 2)
		predefined_sort_logic_size2(list_a, LIST_A);
	else if (list_a->size == 3)
		predefined_sort_logic_size3(list_a);
	else if (list_a->size == 4 || list_a->size == 5)
		predefined_sort_logic_size4_5(list_a, list_b);
}
