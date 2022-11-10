/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:03:02 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 20:00:37 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	count_strings(char **strings)
{
	int	size;

	size = 0;
	while (strings[size] != NULL)
		size++;
	return (size);
}

int	is_overlaped(int number, t_list *list_a)
{
	t_node	*current_node;

	current_node = list_a->head->next;
	while (current_node->next != NULL)
	{
		if (number == (current_node->number))
			return (1);
		current_node = current_node->next;
	}
	return (0);
}

void	free_strings(char **strings)
{
	int	i;
	int	number_of_strings;

	i = 0;
	number_of_strings = count_strings(strings);
	while (i < number_of_strings)
	{
		ft_free(strings[i]);
		i++;
	}
	ft_free(strings);
}

void	parse_arguments(int argc, char **argv, t_list *list_a)
{
	int		i;
	int		j;
	int		number;
	char	**strings;

	if (argc == 1)
		ft_exit(NULL, STDOUT_FILENO, EXIT_SUCCESS);
	i = (argc - 1);
	while (i > 0)
	{
		strings = ft_split(argv[i], ' ');
		if (*strings == NULL)
			ft_exit("Error", STDERR_FILENO, EXIT_FAILURE);
		j = (count_strings(strings) - 1);
		while (j >= 0)
		{
			number = ft_atoi(strings[j]);
			if (is_overlaped(number, list_a))
				ft_exit("Error", STDERR_FILENO, EXIT_FAILURE);
			push_head_side(list_a, new_node(number));
			j--;
		}
		free_strings(strings);
		i--;
	}
}
