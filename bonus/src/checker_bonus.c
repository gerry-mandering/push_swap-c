/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:11:29 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 18:33:01 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

int	main(int argc, char **argv)
{
	t_list	list_a;
	t_list	list_b;
	t_list	command_list;

	init_list_ab(&list_a, &list_b);
	init_list(&command_list);
	parse_arguments(argc, argv, &list_a);
	parse_commands(&command_list);
	execute_commands(&command_list, &list_a, &list_b);
	validate_list_ab(&list_a, &list_b);
	clear_list_ab(&list_a, &list_b);
	return (0);
}
