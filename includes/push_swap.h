/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:43:49 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 20:00:19 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../library/ft_printf-c/includes/ft_printf.h"
# include "../library/libft-c/includes/libft.h"

//define list shape
# define MAX_MID_MIN	10
# define MAX_MIN_MID	11
# define MIN_MID_MAX	12
# define MIN_MAX_MID	13
# define MID_MAX_MIN	14
# define MID_MIN_MAX	15

//define list name
# define LIST_A			20
# define LIST_B			21

//define rotate logic
# define RA_AND_RB		0
# define RA_AND_RRB		1
# define RRA_AND_RB		2
# define RRA_AND_RRB	3

//define list_a aligning logic
# define RA				4
# define RRA			5

//define division, only odd number
# define TOTAL_PART		5
# define PIVOT_COUNT	4

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

typedef struct s_number_info
{
	int	number;
	int	index;
}	t_number_info;

typedef struct s_min_rotate
{
	int	count;
	int	number;
}	t_min_rotate;

typedef struct s_rotate_count
{
	int	using_rotate;
	int	using_reverse_rotate;
}	t_rotate_count;

typedef struct s_rotate_info
{
	int	logic_using;
	int	list_a;
	int	list_b;
}	t_rotate_info;

typedef struct s_circulate_point
{
	int	last_num;
	int	first_num;
}	t_circulate_point;

//list_basic.c
int				is_empty(t_list *list);
int				get_first(t_list *list);
int				get_last(t_list *list);
void			init_list(t_list *list);
void			init_list_ab(t_list *list_a, t_list *list_b);

//list_push_pop.c
t_node			*new_node(int number);
void			push_head_side(t_list *list, t_node *new_node);
void			push_tail_side(t_list *list, t_node *new_node);
t_node			*pop_head_side(t_list *list);
t_node			*pop_tail_side(t_list *list);

//list_clear.c
void			clear_list(t_list *list);
void			clear_list_ab(t_list *list_a, t_list *list_b);

//list_command_push.c
void			push_source_first_to_target(t_list *source_list, \
											t_list *target_list);
void			pa(t_list *list_b, t_list *list_a);
void			pb(t_list *list_a, t_list *list_b);

//list_command_swap.c
void			swap_first_second(t_list *list);
void			sa(t_list *list_a);
void			sb(t_list *list_b);
void			ss(t_list *list_a, t_list *list_b);

//list_command_rotate.c
void			rotate(t_list *list);
void			ra(t_list *list_a);
void			rb(t_list *list_b);
void			rr(t_list *list_a, t_list *list_b);

//list_command_reverse_rotate.c
void			reverse_rotate(t_list *list);
void			rra(t_list *list_a);
void			rrb(t_list *list_b);
void			rrr(t_list *list_a, t_list *list_b);

//parse_arguments.c
int				count_strings(char **strings);
int				is_overlaped(int number, t_list *list_a);
void			free_strings(char **strings);
void			parse_arguments(int argc, char **argv, t_list *list_a);

//sort_array.c
void			insertion_sort(int *array, int size);
void			sort_array(int *array, int size);

//is_sorted.c
int				is_sorted(t_list *list);

//predefined_logic_utils.c
int				get_list_shape(int *num_array);
int				get_index(int selected_number, t_list *list_a);
void			push_two_min_numbers_to_list_b(t_list *list_a, t_list *list_b);

//sort_with_predefined_logic.c
void			predefined_sort_logic_size2(t_list *list, int list_name);
void			predefined_reverse_sort_logic_size2(t_list *list, \
													int list_name);
void			predefined_sort_logic_size3(t_list *list);
void			predefined_sort_logic_size4_5(t_list *list_a, t_list *list_b);
void			sort_with_predefined_logic(t_list *list_a, t_list *list_b);

//sort_with_greedy_algorithm.c
void			copy_numbers_to_array(int **num_array, t_list *list);
void			set_pivot(int *pivot, t_list *list_a);
void			pb_and_rb(t_list *list_a, t_list *list_b);
void			divide_list(int *num_array, \
							int *pivot, t_list *list_a, t_list *list_b);
void			sort_with_greedy_algorithm(t_list *list_a, t_list *list_b);

//greedy_sort.c
void			greedy_sort(t_list *list_a, t_list *list_b);

//set_list_b_rotate.c
void			set_list_b_rotate(t_rotate_count *list_b_rotate, \
									int node_index, t_list *list_b);

//set_list_a_rotate.c
int				get_diff_abs(int num_a, int num_b);
t_number_info	get_closest_number_info(int selected_number, t_list *list_a);
void			set_closest_number_to_top(t_rotate_count *list_a_rotate, \
											int number_index, t_list *list_a);
void			set_closest_number_to_bottom(t_rotate_count *list_a_rotate, \
											int number_index, t_list *list_a);
void			set_list_a_rotate(t_rotate_count *list_a_rotate, \
									int selected_number, t_list *list_a);

//get_min_max.c
int				get_max2(int num_a, int num_b);
int				get_min4(int *num_arr);
int				get_max_index(int *num_arr, int size);
int				get_min_index(int *num_arr, int size);

//set_rotate_info.c
int				count_min_rotate(t_rotate_count *list_a_rotate, \
								t_rotate_count *list_b_rotate);
int				get_rotate_logic(t_rotate_count *list_a_rotate, \
								t_rotate_count *list_b_rotate);
void			calculate_rotate_info(t_rotate_info *rotate_info, \
				t_rotate_count *list_a_rotate, t_rotate_count *list_b_rotate);
void			set_rotate_info(t_rotate_info *rotate_info, \
								t_list *list_a, t_list *list_b);

//rotate_list_ab.c
void			rotate_both(t_rotate_info *rotate_info, \
							t_list *list_a, t_list *list_b);
void			rotate_list_a(t_rotate_info *rotate_info, t_list *list_a);
void			rotate_list_b(t_rotate_info *rotate_info, t_list *list_b);
void			rotate_list_ab(t_rotate_info *rotate_info, \
								t_list *list_a, t_list *list_b);

//align_list_a.c
int				get_min_number_index(t_list *list_a);
t_rotate_count	get_list_a_align(int min_number_index, t_list *list_a);
int				get_align_logic(int using_rotate, int using_reverse_rotate);
void			align_list_a(t_list *list_a);

#endif
