/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:38:46 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 20:00:40 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted(t_list *list)
{
	t_node	*current_node;

	current_node = list->head->next;
	while (current_node->next != NULL)
	{
		if (current_node->prev != list->head)
		{
			if (current_node->prev->number > current_node->number)
				return (0);
		}
		current_node = current_node->next;
	}
	return (1);
}
