/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_list_ab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:05:58 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 20:01:11 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_both(t_rotate_info *rotate_info, \
		t_list *list_a, t_list *list_b)
{
	if (rotate_info->logic_using == RA_AND_RRB || \
			rotate_info->logic_using == RRA_AND_RB)
		return ;
	while ((rotate_info->list_a != 0) && (rotate_info->list_b != 0))
	{
		if (rotate_info->logic_using == RA_AND_RB)
			rr(list_a, list_b);
		else
			rrr(list_a, list_b);
		(rotate_info->list_a)--;
		(rotate_info->list_b)--;
	}
}

void	rotate_list_a(t_rotate_info *rotate_info, t_list *list_a)
{
	while (rotate_info->list_a != 0)
	{
		if (rotate_info->logic_using == RA_AND_RB || \
				rotate_info->logic_using == RA_AND_RRB)
			ra(list_a);
		else
			rra(list_a);
		(rotate_info->list_a)--;
	}
}

void	rotate_list_b(t_rotate_info *rotate_info, t_list *list_b)
{
	while (rotate_info->list_b != 0)
	{
		if (rotate_info->logic_using == RA_AND_RB || \
				rotate_info->logic_using == RRA_AND_RB)
			rb(list_b);
		else
			rrb(list_b);
		(rotate_info->list_b)--;
	}
}

void	rotate_list_ab(t_rotate_info *rotate_info, \
		t_list *list_a, t_list *list_b)
{
	rotate_both(rotate_info, list_a, list_b);
	rotate_list_a(rotate_info, list_a);
	rotate_list_b(rotate_info, list_b);
}
