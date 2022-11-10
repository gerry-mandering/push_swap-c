# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 14:17:19 by minseok2          #+#    #+#              #
#    Updated: 2022/11/10 14:44:17 by minseok2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rcs
RM = rm
RMFLAGS = -rf

HEADER_DIR = includes

SRCS_DIR = src
SRCS = branch_c \
		branch_di \
		branch_di_util1 \
		branch_di_util2 \
		branch_di_util3 \
		branch_p \
		branch_p_util1 \
		branch_s \
		branch_type \
		branch_u \
		branch_u_util1 \
		branch_u_util2 \
		branch_x \
		branch_x_util1 \
		branch_x_util2 \
		branch_x_util3 \
		ft_printf \
		judgement_functions \
		libft_functions \
		parse_funcions \
		string_util_functions

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(SRCS)))

all: $(NAME)

clean:
	$(RM) $(RMFLAGS) $(OBJS_DIR)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re:
	make fclean
	make all

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER_DIR)

.PHONY : all bonus clean fclean re
