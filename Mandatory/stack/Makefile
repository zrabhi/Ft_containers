# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 08:47:35 by zrabhi            #+#    #+#              #
#    Updated: 2023/02/11 16:06:45 by zrabhi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


BLUE 	:= \033[1;34m
SRC 	:= stack_test.cpp 
CC 		:= clang++
RM 		:= rm -f
OBJ		:= $(SRC:%.cpp=%.o)
FLAG	:= -Wall -Werror -Wextra -std=c++98 -g
STD 	:=  -D STL=1
FT		:=	-D STL=0
NAME 	:= FTstack
STL 	:= STDstack
# ASCII	:= ../map/ 
HEADERS := stack.hpp

all: $(NAME)
	@echo ""
	@echo " \n$(BLUE)Creating :Stack...$(BLUE)"
	@echo " \n"
	
stl : $(STL)

$(NAME) : $(OBJ)
	$(CC) $(FT) $(FLAG) $(SRC) -o $(NAME)

%.o: %.cpp $(HEADERS)
	@$(CC) $(FLAG) -c $< -o $@

$(STL) : $(OBJ)
	$(CC) $(STD) $(FLAG) $(SRC) -o $(STL)
	
clean:
	@$(RM) $(OBJ)
	@echo " $(BLUE)Removing obj...$(BLUE)"
	
fclean : clean
	@echo " $(BLUE)file removed succesfully$(BLUE)"
	@$(RM) $(NAME) $(STL)
	
re : fclean all