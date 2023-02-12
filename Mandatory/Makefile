# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/24 15:29:49 by zrabhi            #+#    #+#              #
#    Updated: 2023/02/12 12:35:27 by zrabhi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLUE := \033[1;34m
VECTOR 	:= vector
MAP     := map
STACK 	:= stack
S_HEADER := $(STACK)/stack.hpp
V_HEADER := $(VECTOR)/vector.hpp
M_HEADER := $(MAP)/map.hpp
UTILS    := utils
AVLTREE := AvlTree
ITERATOR := iterator
HEADERS  :=  $(UTILS)/ft_defines.hpp  $(UTILS)/ft_algorithm.hpp $(UTILS)/ft_enable_if.hpp $(UTILS)/ft_is_integral.hpp $(UTILS)/ft_utility.hpp \
			$(ITERATOR)/iterator_vecto.hpp $(ITERATOR)/iteretor_traits.hpp $(ITERATOR)/reverse_iterator.hpp $(AVLTREE)/AvlTree.hpp  $(STACK)/stack.hpp \
			$(VECTOR)/vector.hpp  $(MAP)/map.hpp
SRC 	:= $(VECTOR)/vector_tests.cpp  $(STACK)/stack_test.cpp $(MAP)/map_tests.cpp main.cpp
CC 		:= c++
RM 		:= rm -f
OBJ		:= $(SRC:%.cpp=%.o)
FLAG	:= -Wall -Werror -Wextra -std=c++98 
STD 	:= -D STL=1
FT		:= -D STL=0
NAME 	:= FTcontainers
STL 	:= STDcontainers
HEADERS := Map.hpp


all : $(NAME)
	@echo ""
	@echo "\n$(BLUE)Making....$(BLUE)"
	@sleep 1 
	@cat ascii-art.ans
	@sleep 1.5
	@echo " \n"
	
stl : $(STL)


$(NAME):   $(OBJ)
	@$(CC) $(FT) $(FLAG) $(SRC) -o $(NAME)

$(STL) : $(OBJ)
	@$(CC) $(STD) $(FLAG) $(SRC) -o $(STL)

%.o: %.cpp $(HEADERS)
	@$(CC) $(FT)$(FLAG) -c $< -o $@
	
clean:
	@$(RM) $(OBJ) 
	@echo " $(BLUE)Removing obj...$(BLUE)"

fclean : clean
	@echo " $(BLUE)file removed succesfully$(BLUE)"
	@$(RM) $(NAME) $(STL)
	
re : fclean all
