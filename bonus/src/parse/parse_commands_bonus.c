/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:51:16 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 18:33:35 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

void	parse_commands(t_list *command_list)
{
	char	*input_command;
	char	**command_table;

	command_table = ft_split("sa sb ss pa pb ra rb rr rra rrb rrr", ' ');
	while (1)
	{
		input_command = get_next_line(0);
		if (input_command == NULL)
			break ;
		push_command_to_list(input_command, command_table, command_list);
	}
	free_command_table(command_table);
}
