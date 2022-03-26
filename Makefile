# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shovsepy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 15:20:34 by shovsepy          #+#    #+#              #
#    Updated: 2022/03/26 17:45:21 by shovsepy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS = $(wildcard src/*.c)

OBJS = $(SRCS:.c=.o)

CC = cc

INCLUDES = -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

.c.o:
	$(CC) $(FLAGS)  -Imlx -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C ./mlx
	@$(CC) $(OBJS) $(FLAGS) $(INCLUDES) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

norm:
	@norminette $(SRCS)

re: fclean all

.PHONY: all clean fclean norm re
