# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/21 12:49:56 by adiaz-lo          #+#    #+#              #
#    Updated: 2023/09/26 11:56:36 by adiaz-lo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

DEPS = libft/libft.a

CC = clang

SRC_DIR = src/

CCFLAGS = -g3 #-Wall -Werror -Wextra -pedantic -O3

INCLUDE = includes/pipex.h

ARFLAGS = -rcs

RM = rm -f

SRCS = pipex.c check_args.c free_pipex.c search_path.c throw_error.c check_command_access.c exec_first_child.c exec_second_child.c

DIR_PREFIX = $(addprefix $(SRC_DIR), $(SRCS))

OBJS = $(DIR_PREFIX:.c=.o)

TEST = main.c

TEST_OUT = ./pipex

all : $(NAME)

%.o : %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

$(DEPS): 
	make -C libft

$(NAME): $(DEPS) $(INCLUDE) $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) $(DEPS) -o $(NAME)

clean : 
	$(RM) $(OBJS)
	make -C libft fclean

fclean : clean
	$(RM) $(NAME)

test : $(DEPS) $(SRCS) $(TEST) $(INCLUDE)
	$(CC) $(CCFLAGS) $(SRCS) $(TEST) $(DEPS) && $(TEST_OUT)

re : fclean all
