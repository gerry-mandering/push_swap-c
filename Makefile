# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/05 10:50:33 by minseok2          #+#    #+#              #
#    Updated: 2023/12/06 18:28:18 by minseok2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -rf

LIBFT_DIR = library/libft-c
LIBFT_NAME = ft
LIBPRINTF_DIR = library/ft_printf-c
LIBPRINTF_NAME = printf
LIBGNL_DIR = library/get_next_line-c
LIBGNL_NAME = gnl

# mandatory
HEADER_DIR = includes

SRCS_DIR = src
SRCS = push_swap.c \
	   list_command/list_basic.c \
	   list_command/list_push_pop.c \
	   list_command/list_clear.c \
	   list_command/list_command_push.c \
	   list_command/list_command_swap.c \
	   list_command/list_command_rotate.c \
	   list_command/list_command_reverse_rotate.c \
	   list_util/is_sorted.c \
	   parse_arguments/parse_arguments.c \
	   sort_array/sort_array.c \
	   predefined_logic/sort_with_predefined_logic.c \
	   predefined_logic/predefined_logic_utils.c \
	   greedy_sort/sort_with_greedy_algorithm.c \
	   greedy_sort/greedy_sort.c \
	   greedy_sort/get_min_max.c \
	   greedy_sort/set_rotate_info.c \
	   greedy_sort/set_list_a_rotate.c \
	   greedy_sort/set_list_b_rotate.c \
	   greedy_sort/rotate_list_ab.c \
	   greedy_sort/align_list_a.c

OBJS_DIR = objs/mandatory
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

# bonus
BONUS_HEADER_DIR = bonus/includes

BONUS_SRCS_DIR = bonus/src
BONUS_SRCS = checker_bonus.c \
			 list_command/list_basic_bonus.c \
			 list_command/list_push_pop_bonus.c \
			 list_command/list_clear_bonus.c \
			 list_command/list_command_push_bonus.c \
			 list_command/list_command_swap_bonus.c \
			 list_command/list_command_rotate_bonus.c \
			 list_command/list_command_reverse_rotate_bonus.c \
			 list_util/is_sorted_bonus.c \
			 parse/parse_arguments_bonus.c \
			 parse/parse_commands_bonus.c \
			 checker_utils/execute_commands_bonus.c \
			 checker_utils/validate_list_ab_bonus.c

BONUS_OBJS_DIR = objs/bonus
BONUS_OBJS = $(BONUS_SRCS:%.c=$(BONUS_OBJS_DIR)/%.o)

TOTAL_OBJS_DIR = objs

all: $(NAME)

bonus: $(NAME) $(BONUS_NAME)

clean:
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(LIBPRINTF_DIR)
	make fclean -C $(LIBGNL_DIR)
	$(RM) $(RMFLAGS) $(TOTAL_OBJS_DIR)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME) $(BONUS_NAME)

re:
	make fclean
	make all

$(NAME): $(OBJS)
	make all -C $(LIBFT_DIR)
	make all -C $(LIBPRINTF_DIR)
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) -l$(LIBFT_NAME) -L$(LIBPRINTF_DIR) -l$(LIBPRINTF_NAME) -o $@ $^

$(BONUS_NAME): $(BONUS_OBJS)
	make all -C $(LIBFT_DIR)
	make all -C $(LIBPRINTF_DIR)
	make all -C $(LIBGNL_DIR)
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) -l$(LIBFT_NAME) -L$(LIBPRINTF_DIR) -l$(LIBPRINTF_NAME) -L$(LIBGNL_DIR) -l$(LIBGNL_NAME) -o $@ $^

$(OBJS): $(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR)/{list_command,list_util,parse_arguments,sort_array,predefined_logic,greedy_sort}
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER_DIR)

$(BONUS_OBJS): $(BONUS_OBJS_DIR)/%.o: $(BONUS_SRCS_DIR)/%.c
	mkdir -p $(BONUS_OBJS_DIR)/{list_command,list_util,parse,checker_utils}
	$(CC) $(CFLAGS) -c $< -o $@ -I$(BONUS_HEADER_DIR)

.PHONY : all bonus clean fclean re
