# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/02 22:21:18 by mmeising          #+#    #+#              #
#    Updated: 2023/05/12 20:49:23 by mmeising         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


VPATH := ./src/
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -g
INC := -I .

CXX := c++

NAME := ./PmergeMe

SRC := PmergeMe main
SRC := $(SRC:%=%.cpp)

OBJ := $(addprefix ./_obj/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ $(INC) -o $@

./_obj/%.o: %.cpp
	@mkdir -p _obj
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< $(INC) -o $@

clean:
	rm -rf _obj/

fclean: clean
	rm -f $(NAME)

re:	fclean
	make

.PHONY: clean fclean
