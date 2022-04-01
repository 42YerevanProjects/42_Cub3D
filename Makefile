# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabajyan <aabajyan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 15:20:34 by shovsepy          #+#    #+#              #
#    Updated: 2022/04/01 17:33:31 by shovsepy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
SRCS = $(wildcard utils/*.c src/*.c)
OBJS = $(SRCS:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror -g -O0 -Iincludes
LDFLAGS = $(CFLAGS) -lmlx -lm
UNAME = $(shell uname -s)

ifeq ($(UNAME), Linux)
	CFLAGS  += -I/usr/X11/include
	LDFLAGS += -L/usr/X11/lib -lXext -lX11
endif

ifeq ($(UNAME), Darwin)
	CFLAGS += -Imlx
	LDFLAGS	+= -Lmlx -framework OpenGL -framework AppKit
endif

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

all: $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

norm:
	@norminette $(SRCS)

.PHONY: clean re fclean all norm
