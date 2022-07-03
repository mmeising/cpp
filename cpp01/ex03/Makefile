# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 00:31:45 by mmeising          #+#    #+#              #
#    Updated: 2022/07/03 04:54:05 by mmeising         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VPATH := 

NAME := violence

CC := c++
CFLAGS := -Wall -Werror -Wextra

SRC := main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

OBJ_DIR := _obj
OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

# LIB =
# INC = -I ./include

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ $(LIB) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< $(INC) -o $@

clean:
	@if [ -d "${OBJ_DIR}" ]; then \
		rm -r ${OBJ_DIR}; \
		printf "cleaned object files\n"; \
	fi

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		rm $(NAME); \
		printf "cleaned program\n"; \
	fi
		
re: fclean all

.PHONY: all clean fclean re

-include $(OBJ:.o=.d)