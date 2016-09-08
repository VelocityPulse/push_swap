# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/05 16:30:43 by cchameyr          #+#    #+#              #
#    Updated: 2016/09/08 15:35:28 by cchameyr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES_SWAP =			main.c

FILES_CHECKER =			main.c

SRC_SWAP =				$(addprefix src_swap/, $(FILES_SWAP))

SRC_CHECKER =			$(addprefix src_checker/, $(FILES_CHECKER))

OBJS_SWAP =				$(addprefix obj_swap/, $(FILES_SWAP:.c=.o))

OBJS_CHECKER =			$(addprefix obj_checker/, $(FILES_CHECKER:.c=.o))

CC =					gcc

NAME_SWAP =				push_swap

NAME_CHECKER =			checker

LIBFT =					libft/libft.a

DEBUGSEGFAULT =			-fsanitize=address

FLAGS =					-Wall -Wextra -Werror #$(DEBUGSEGFAULT)

RM =					rm -rf

all: $(NAME_CHECKER) $(NAME_SWAP)

$(NAME_CHECKER): $(LIBFT) $(OBJS_CHECKER)
	$(CC) $(FLAGS) $(OBJS_CHECKER) $(LIBFT) -o $(NAME_CHECKER)

$(OBJS_CHECKER):
	$(CC) $(FLAGS) -c $(SRC_CHECKER)
	@make obj_checker_mv

obj_checker_mv:
	@mkdir obj_checker
	@mv $(FILES_SWAP:.c=.o) ./obj_checker/

obj_checker_rm:
	@$(RM) ./obj_checker


$(NAME_SWAP): $(LIBFT) $(OBJS_SWAP)
	$(CC) $(FLAGS) $(OBJS_SWAP) $(LIBFT) -o $(NAME_SWAP)

$(OBJS_SWAP):
	$(CC) $(FLAGS) -c $(SRC_SWAP)
	@make obj_swap_mv

obj_swap_mv:
	@mkdir obj_swap
	@mv $(FILES_SWAP:.c=.o) ./obj_swap/

obj_swap_rm:
	@$(RM) ./obj_swap


$(LIBFT):
	make -C ./libft/

clean: obj_swap_rm obj_checker_rm
	make clean -C ./libft/

fclean: clean
	$(RM) $(LIBFT) $(NAME_SWAP) $(NAME_CHECKER)

re: fclean all

r: obj_swap_rm obj_checker_rm
	$(RM) $(NAME_SWAP) $(NAME_CHECKER)
	@make
