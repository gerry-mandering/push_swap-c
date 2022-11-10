/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:02:14 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 19:57:46 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	list_a;
	t_list	list_b;

	init_list_ab(&list_a, &list_b);
	parse_arguments(argc, argv, &list_a);
	if (is_sorted(&list_a))
		ft_exit(NULL, STDOUT_FILENO, EXIT_SUCCESS);
	if (list_a.size <= 5)
		sort_with_predefined_logic(&list_a, &list_b);
	else
		sort_with_greedy_algorithm(&list_a, &list_b);
	clear_list_ab(&list_a, &list_b);
	return (0);
}
