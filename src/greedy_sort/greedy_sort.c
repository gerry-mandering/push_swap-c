/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:01:10 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 20:01:13 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	greedy_sort(t_list *list_a, t_list *list_b)
{
	t_rotate_info	rotate_info;

	while (list_b->size != 0)
	{
		set_rotate_info(&rotate_info, list_a, list_b);
		rotate_list_ab(&rotate_info, list_a, list_b);
		pa(list_b, list_a);
	}
	align_list_a(list_a);
}
