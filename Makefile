# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/21 12:49:56 by adiaz-lo          #+#    #+#              #
#    Updated: 2024/05/08 15:29:20 by adiaz-lo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

DEPS = libft/libft.a

CC = gcc

SRC_DIR = src/

CCFLAGS = -Wall -Werror -Wextra -pedantic

	CCFLAGS += -fsanitize=address -g3 -fsanitize=leak

INCLUDE = includes/pipex.h

ARFLAGS = -rcs

RM = rm -f

SRCS = pipex.c check_args.c free_pipex.c search_path.c throw_error.c check_command_access.c exec_first_child.c exec_second_child.c save_args.c return_exec_code.c execution.c print_error.c

DIR_PREFIX = $(addprefix $(SRC_DIR), $(SRCS))

OBJS = $(DIR_PREFIX:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CCFLAGS) -c -o $@ $<
	#$(CC) -c -o $@ $<

$(DEPS): 
	make -C libft

$(NAME): $(DEPS) $(INCLUDE) $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) $(DEPS) -o $(NAME)
	#$(CC) $(OBJS) $(DEPS) -o $(NAME)

clean : 
	$(RM) $(OBJS)
	make -C libft fclean

fclean : clean
	$(RM) $(NAME)

re : fclean all
