/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:12:03 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 20:00:53 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	clear_list(t_list *list)
{
	t_node	*current_node;
	t_node	*next_node;

	current_node = list->head->next;
	while (current_node->next != NULL)
	{
		next_node = current_node->next;
		ft_free(current_node);
		current_node = next_node;
	}
	ft_free(list->head);
	ft_free(list->tail);
}

void	clear_list_ab(t_list *list_a, t_list *list_b)
{
	clear_list(list_a);
	clear_list(list_b);
}
