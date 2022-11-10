# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 11:00:34 by minseok2          #+#    #+#              #
#    Updated: 2022/11/10 19:47:50 by minseok2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rcs
RM = rm
RMFLAGS = -rf

HEADER_DIR = includes

SRCS_DIR = src
SRCS = ft_isalpha \
		ft_isdigit \
		ft_isalnum \
		ft_isspace \
		ft_isascii \
		ft_isprint \
		ft_toupper \
		ft_tolower \
		ft_bzero \
		ft_memset \
		ft_memcpy \
		ft_memmove \
		ft_memcmp \
		ft_memchr \
		ft_strlen \
		ft_strlcpy \
		ft_strlcat \
		ft_strncmp \
		ft_strchr \
		ft_strrchr \
		ft_strnstr \
		ft_strdup \
		ft_substr \
		ft_strjoin \
		ft_strtrim \
		ft_split \
		ft_strmapi \
		ft_striteri \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_atoi \
		ft_itoa \
		ft_malloc \
		ft_calloc \
		ft_exit \
		ft_free

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

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER_DIR)

.PHONY: all clean fclean re bonus
