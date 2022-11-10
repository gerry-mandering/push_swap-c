/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 01:33:22 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 20:00:57 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_empty(t_list *list)
{
	if ((list->size) == 0)
		return (1);
	else
		return (0);
}

int	get_first(t_list *list)
{
	t_node	*first_node;

	if (is_empty(list))
		ft_exit("list is empty", STDERR_FILENO, EXIT_FAILURE);
	first_node = list->head->next;
	return (first_node->number);
}

int	get_last(t_list *list)
{
	t_node	*last_node;

	if (is_empty(list))
		ft_exit("list is empty", STDERR_FILENO, EXIT_FAILURE);
	last_node = list->tail->prev;
	return (last_node->number);
}

//use ft_calloc to set (size), (head->prev), (tail->next) NULL
void	init_list(t_list *list)
{
	list->head = (t_node *)ft_calloc(1, sizeof(t_node));
	list->tail = (t_node *)ft_calloc(1, sizeof(t_node));
	list->head->next = list->tail;
	list->tail->prev = list->head;
	list->size = 0;
}

void	init_list_ab(t_list *list_a, t_list *list_b)
{
	init_list(list_a);
	init_list(list_b);
}
