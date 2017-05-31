# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thou <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/30 12:16:59 by thou              #+#    #+#              #
#    Updated: 2017/05/31 17:17:13 by ibtraore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK		=	\033[30;1m
RED			=	\033[31;1m
GREEN		=	\033[32;1m
YELLOW		=	\033[33;1m
BLUE		=	\033[34;1m
PURPLE		=	\033[35;1m
CYAN		=	\033[36;1m
WHITE		=	\033[37;1m
RESET		=	\033[0m
CLEAR		=	\033[H\e[J

NAME		=	OMEN
FLAG		=	-Wall -Werror -Wextra
SRC_DIR		=	src/
SRC_BASE	=	main.c get_antennes.c get_gps.c get_attenuation.c ispointvalide.c get_field.c search.c
SRC			=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJ_DIR		=	obj/
LIBFT		=	./libft
LFT			=	./libft/libft.a
INCLUDES	=	-I./includes -I./libft/includes
OBJ			=	$(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

all: $(LFT) $(NAME)

$(LFT):
	@make -C $(LIBFT)

$(NAME): $(OBJ)
	@gcc $(FLAG) $(OBJ) -o $(NAME) -L$(LIBFT) -lft $(INCLUDES)
	@echo "\033[48;5;15;38;5;25;1mMAKE $(NAME) DONE$(RESET)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAG) -o $@ -c $< $(INCLUDES)


clean:
	@make clean -C $(LIBFT)
	@rm -rf obj

fclean:
	@make fclean -C $(LIBFT)
	@rm -rf obj
	@rm -rf $(NAME)
	@echo "$(YELLOW)Clean	$(NAME)$(GREEN)			[ OK ]$(RESET)"

re: fclean all
