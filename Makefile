# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 14:36:04 by mmervoye          #+#    #+#              #
#    Updated: 2019/01/07 16:17:53 by mmervoye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm
DEBUG = no

# Set the compiler used
CC = gcc

# Set the flags used by the compiler, if DEBUG=yes, use debug flags
ifeq ($(DEBUG), yes)
	CFLAGS = -Wall -Wextra -fsanistize=address -g3
else
	CFLAGS = -Wall -Wextra -Werror
endif

# Defining the folders used
OBJ_PATH = ./objs/
INC_PATH = ./incs/
SRC_PATH = ./srcs/

# Defining explicites sources and objects
SRC_NAME = main.c
OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

LIBFT_INC_PATH = ./libft/incs/
LIBFT_FLAG = -Llibft -lft

# Defining Colors
YELLOW = "\\033[033m"
GREEN = "\\033[032m"
NONE = "\\033[0m"

# Defining done phrase used later

DONE = "$(NONE)\033[2K\r"

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
	@printf "$(YELLOW)Compiling $(NAME)"
	@$(CC) -o $(NAME) -I $(INC_PATH) -I $(LIBFT_INC_PATH) $(LIBFT_FLAG) -o $(NAME) $(OBJ)
	@printf $(DONE)
	@printf "$(GREEN)makefile: $(NAME) compiled !\n"

$(OBJ_PATH):
	@printf "Creating $(OBJ_PATH)"
	@mkdir -p $(OBJ_PATH) 2>&- # Creating objs folder and close sdterr
	@printf $(DONE)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@printf "$(GREEN)Compiling $@"
	@$(CC) $(CC_FLAG) -o $@ -c $<
	@printf $(DONE)

clean:
	@printf "$(YELLOW)Cleaning objects"
	@rm -f $(OBJ)
	@printf $(DONE)
	@printf "$(YELLOW)Cleaning $(OBJ_PATH)"
	@rm -rf $(OBJ_PATH) 2>&-
	@printf $(DONE)

fclean: clean
	@printf "$(YELLOW)Cleaning $(NAME)"
	@rm -f $(NAME)
	@printf $(DONE)

re: fclean all

.PHONY: fclean clean all
