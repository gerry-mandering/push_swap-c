/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_list_b_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:16:58 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 20:01:06 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	set_list_b_rotate(t_rotate_count *list_b_rotate, \
		int node_index, t_list *list_b)
{
	if (node_index == 0)
	{
		list_b_rotate->using_rotate = 0;
		list_b_rotate->using_reverse_rotate = 0;
	}
	else
	{
		list_b_rotate->using_rotate = node_index;
		list_b_rotate->using_reverse_rotate = (list_b->size) - node_index;
	}
}
