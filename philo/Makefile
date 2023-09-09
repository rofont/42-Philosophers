# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romain <romain@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 10:04:59 by rofontai          #+#    #+#              #
#    Updated: 2023/09/08 22:26:30 by romain           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define BANNER
$R   ___ _     _ _                       _
$R  / _ \ |__ (_) | ___  ___  ___  _ __ | |__   ___ _ __
$G / /_)/ '_ \| | |/ _ \/ __|/ _ \| '_ \| '_ \ / _ \ '__|
$C/ ___/| | | | | | (_) \__ \ (_) | |_) | | | |  __/ |
$Y\/    |_| |_|_|_|\___/|___/\___/| .__/|_| |_|\___|_|
$Y                                |_|
$W
endef
export

# ARGUMENTS--------------------------------------------------------------------

NAME		= philo

CC			= gcc
CFLAGS		= -g -Wall -Wextra -Werror -pthread #-fsanitize=thread

DIR_SRC		= ./src
SRC			= main.c \
				parsing.c \
				init.c \
				a_supp.c \
				routine.c \
				utils.c \

DIR_OBJ		= ./obj
OBJ			= $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))

DIR_HEAD	= ./include
HEADER		= $(DIR_HEAD)/philo.h

# COLORS-----------------------------------------------------------------------

R = $(shell tput -Txterm setaf 1)
G = $(shell tput -Txterm setaf 2)
W = $(shell tput -Txterm setaf 7)
C = $(shell tput -Txterm setaf 6)
Y = $(shell tput -Txterm setaf 3)
Z = $(shell tput -Txterm setaf 5)

# RULES------------------------------------------------------------------------

all	: $(NAME)
	@echo "$$BANNER"
	@echo "\n#-----$CPhilo ready$W ✅---------------#\n"

$(DIR_OBJ)/%.o	:	$(DIR_SRC)/%.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$G Compilation : $Z $(notdir $<)"$W

$(NAME): $(DIR_OBJ) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(DIR_OBJ)	:
	@mkdir -p $@

clean:
	@echo $RCLEAN	DONE$W
	@rm -rf $(DIR_OBJ)

fclean: clean
	@rm -rf $(NAME)
	@echo $RFCLEAN	DONE$W

re: fclean all

leaks:
	@valgrind --track-fds=yes --trace-children=yes --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=supp.txt ./philo

leak:
	@leaks --atExit --list -- ./philo

norminette:
	@norminette

visualizer:
	open https://nafuka11.github.io/philosophers-visualizer/

.PHONY: all clean fclean re leaks leak norminette