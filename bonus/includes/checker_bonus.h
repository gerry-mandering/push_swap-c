/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:34:42 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 18:35:08 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "../../library/libft-c/includes/libft.h"
# include "../../library/ft_printf-c/includes/ft_printf.h"
# include "../../library/get_next_line-c/includes/get_next_line.h"

# define TOTAL_COMMANDS	11

typedef struct s_node
{
	int				number;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	int		size;
	t_node	*head;
	t_node	*tail;
}	t_list;

typedef void	(*t_command_fp)(t_list *list_a, t_list *list_b);

//list_basic_bonus.c
int		is_empty(t_list *list);
int		get_first(t_list *list);
int		get_last(t_list *list);
void	init_list(t_list *list);
void	init_list_ab(t_list *list_a, t_list *list_b);

//list_push_pop_bonus.c
t_node	*new_node(int number);
void	push_head_side(t_list *list, t_node *new_node);
void	push_tail_side(t_list *list, t_node *new_node);
t_node	*pop_head_side(t_list *list);
t_node	*pop_tail_side(t_list *list);

//list_clear_bonus.c
void	clear_list(t_list *list);
void	clear_list_ab(t_list *list_a, t_list *list_b);

//list_command_push_bonus.c
void	push_source_first_to_target(t_list *source_list, \
									t_list *target_list);
void	pa(t_list *list_b, t_list *list_a);
void	pb(t_list *list_a, t_list *list_b);

//list_command_swap_bonus.c
void	swap_first_second(t_list *list);
void	sa(t_list *list_b, t_list *list_a);
void	sb(t_list *list_b, t_list *list_a);
void	ss(t_list *list_a, t_list *list_b);

//list_command_rotate_bonus.c
void	rotate(t_list *list);
void	ra(t_list *list_b, t_list *list_a);
void	rb(t_list *list_b, t_list *list_a);
void	rr(t_list *list_a, t_list *list_b);

//list_command_reverse_rotate_bonus.c
void	reverse_rotate(t_list *list);
void	rra(t_list *list_b, t_list *list_a);
void	rrb(t_list *list_b, t_list *list_a);
void	rrr(t_list *list_a, t_list *list_b);

//parse_arguments_bonus.c
int		count_strings(char **strings);
int		is_overlaped(int number, t_list *list_a);
void	free_strings(char **strings);
void	parse_arguments(int argc, char **argv, t_list *list_a);

//parse_commands_bonus.c
void	parse_commands(t_list *command_list);

//is_sorted_bonus.c
int		is_sorted(t_list *list);

//execute_commands_bonus.c
void	free_command_table(char **command_table);
void	push_command_to_list(char *input_command, \
							char **command_table, t_list *command_list);
void	execute_commands(t_list *command_list, \
							t_list *list_a, t_list *list_b);

//validate_list_ab_bonus.c
void	validate_list_ab(t_list *list_a, t_list *list_b);

#endif
