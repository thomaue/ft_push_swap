# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tauer <tauer@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 17:59:50 by tauer             #+#    #+#              #
#    Updated: 2024/02/13 18:15:09 by tauer            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		=	src
BUILD_DIR	=	build
NAME		=	push_swap
CFLAG		=	-Wall -Wextra -Werror -I./header 


SRC			=	$(SRC_DIR)/checker.c\
				$(SRC_DIR)/clean_moves.c\
				$(SRC_DIR)/edit_list.c\
				$(SRC_DIR)/free.c\
				$(SRC_DIR)/list_utils.c\
				$(SRC_DIR)/main.c\
				$(SRC_DIR)/move.c\
				$(SRC_DIR)/print_utils.c\
				$(SRC_DIR)/print.c\
				$(SRC_DIR)/sort_utils.c\
				$(SRC_DIR)/sort.c\
				$(SRC_DIR)/split_utils.c\
				$(SRC_DIR)/split.c\
				$(SRC_DIR)/three_digits_move.c\
				$(SRC_DIR)/three_digits_set.c\
				$(SRC_DIR)/utils.c\
			
CC			=	cc 

OBJ		=	$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o, $(SRC))


$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC)	$(CFLAG)	-c	$< -o	$@
	@clear
	
all: $(NAME)

$(NAME):$(OBJ)
	@echo $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(CFLAG)
	@clear

clear :
	@clear
	@echo "42Paris : $(NAME)"
	@echo ""

clean : clear
	@rm -rf build/
	@echo "Clean   : *.o in build !"

fclean : clean
	@rm -f $(NAME)
	@echo "Clean   : ./$(NAME)"


re: fclean all clear 

.PHONY: all clean fclean re
