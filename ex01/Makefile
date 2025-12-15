# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/14 21:01:58 by yoshin            #+#    #+#              #
#    Updated: 2025/12/14 21:01:58 by yoshin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = claptrap
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp
HEADERS = ClapTrap.hpp ScavTrap.hpp
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(patsubst %.cpp, %.o, $(SRCS))

fclean: clean
	rm -f $(NAME)

re: fclean all

dev:
	$(CXX) $(CXXFLAGS) -g -DDEBUG $(SRCS) -o $(NAME)

.PHONY: all clean fclean re dev
