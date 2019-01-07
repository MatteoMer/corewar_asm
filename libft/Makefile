# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xmazella <xmazella@student.42.fd>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 14:06:35 by mmervoye          #+#    #+#              #
#    Updated: 2018/12/10 15:47:19 by mmervoye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
DEBUG	= no

INC_PATH= ./incs/
OBJ_PATH= ./obj/
SRC_PATH= ./srcs/

OBJ_NAME= $(SRC_NAME:.c=.o)

SRC_NAME= ft_atoi.c \
	  ft_bzero.c \
	  ft_deltab.c \
	  ft_delfunction.c \
	  ft_isalnum.c \
	  ft_isspace.c\
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_islower.c \
	  ft_isprint.c \
	  ft_isupper.c \
	  ft_itoa.c \
	  ft_lstadd.c \
	  ft_lstdel.c \
	  ft_lstdelone.c \
	  ft_lstiter.c \
	  ft_lstnew.c \
	  ft_lstmap.c \
	  ft_lstreverse.c \
	  ft_memalloc.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memdel.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar.c \
	  ft_putchar_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_endl.c \
	  ft_putnbr_fd.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strclr.c \
	  ft_strcmp.c \
	  ft_strclen.c \
	  ft_strcpy.c \
	  ft_strdel.c \
	  ft_strdup.c \
	  ft_strequ.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strjoinf.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strnequ.c \
	  ft_strnew.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strsplit.c \
	  ft_strstr.c \
	  ft_strsub.c \
	  ft_strtrim.c \
	  ft_tab_to_list.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  get_next_line.c \
	  ft_count_word.c\
	  malloc_error.c


INC		= $(addprefix -I,$(INC_PATH))
OBJ		= $(addprefix $(OBJ_PATH),$(OBJ_NAME))
SRC		= $(addprefix $(SRC_PATH),$(SRC_NAME))

ifndef CC
	CC		= gcc
endif


AR		= ar
RM		= rm

ifndef CC_FLAG
	ifeq ($(DEBUG),yes)
	CC_FLAG	= -Wall -Werror -Wextra -o3
else
	CC_FLAG = -Wall -Werror -Wextra
endif
endif

AR_FLAG	= rcs

OK		= "\033[0;33mOK\033[0;0m\n"

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
	@printf "Creation de $(NAME):"
	@$(AR) $(AR_FLAG) $(NAME) $(OBJ)
	@printf $(OK)

$(OBJ_PATH):
	@printf "Creation de $(OBJ_PATH):"
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	@printf $(OK)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@printf "\033[32mCreation de $@:"
	@$(CC) $(CC_FLAG) $(LIB) $(INC) -o $@ -c $<
	@printf " \033[0m\033[2K\r"

clean:
	@printf "Clean des obj:"
	@$(RM) -f $(OBJ)
	@printf " done\n"
	@printf "Clean $(OBJ_PATH):"
	@$(RM) -rf $(OBJ_PATH) 2> /dev/null
	@printf " done\n"

fclean: clean
	@printf "Clean $(NAME):"
	@$(RM) -f $(NAME)
	@printf " done\n"

re: fclean all

norme:
	@printf "\tNorme de $(SRC)\n"
	@norminette $(SRC)
	@printf "\tNorme de $(INC_PATH)\n"
	@norminette $(INC_PATH)

