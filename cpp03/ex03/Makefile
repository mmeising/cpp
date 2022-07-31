# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 22:48:32 by mmeising          #+#    #+#              #
#    Updated: 2022/07/31 17:07:31 by mmeising         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VPATH := 

NAME := dia

CC := c++
CFLAGS := -Wall -Wextra

SRC := main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

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