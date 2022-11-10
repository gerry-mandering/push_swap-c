/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:54:42 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 18:36:00 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

void	free_command_table(char **command_table)
{
	int	i;

	i = 0;
	while (i < TOTAL_COMMANDS)
	{
		ft_free(command_table[i]);
		i++;
	}
	ft_free(command_table);
}

void	push_command_to_list(char *input_command, \
		char **command_table, t_list *command_list)
{
	int		i;
	int		input_command_len;

	i = 0;
	input_command_len = ft_strlen(input_command);
	if (input_command[input_command_len - 1] == '\n')
		input_command_len--;
	while (command_table[i] != NULL && input_command_len != 0)
	{
		if (ft_memcmp(input_command, command_table[i], input_command_len) == 0)
		{
			push_tail_side(command_list, new_node(i));
			ft_free(input_command);
			return ;
		}
		i++;
	}
	ft_exit("Error", STDERR_FILENO, EXIT_FAILURE);
}

void	execute_commands(t_list *command_list, t_list *list_a, t_list *list_b)
{
	const t_command_fp	commands_fp[TOTAL_COMMANDS] = {
		sa, sb, ss,
		pa, pb,
		ra, rb, rr,
		rra, rrb, rrr
	};
	t_node				*current_node;
	int					command;

	while (command_list->size != 0)
	{
		current_node = pop_head_side(command_list);
		command = current_node->number;
		(*commands_fp[command])(list_a, list_b);
		ft_free(current_node);
	}
	clear_list(command_list);
}
