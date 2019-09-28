# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trobbin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 15:48:48 by trobbin           #+#    #+#              #
#    Updated: 2019/09/25 18:09:07 by trobbin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line
INCLUDE = -Ilibft
FLAGS = -Wall -Wextra -Werror
FUNCTIONS = get_next_line

all: $(NAME)

norm:
	@norminette -R CheckForbiddenSourceHeader $(addsuffix .c,$(FUNCTIONS))

$(NAME): norm
	@gcc $(FLAGS) $(INCLUDE) $(addsuffix .c,$(FUNCTIONS)) -Llibft -lft -o $(NAME)

fclean:
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all fclean norm re
