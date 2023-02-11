# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 01:05:07 by zrabhi            #+#    #+#              #
#    Updated: 2023/02/11 17:59:46 by zrabhi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


BLUE 	:= \033[1;34m
SRC 	:= vector_tests.cpp 
CC 		:= clang++
RM 		:= rm -f
OBJ		:= $(SRC:%.cpp=%.o)
STD 	:=  -D STL=1
FT		:=	-D STL=0
FLAG	:=  -Wall -Werror -Wextra -std=c++98
NAME 	:= FTvector
STL 	:= STDvector
HEADERS := vector.hpp

all: $(NAME)
	@echo ""
	@echo " \n$(BLUE)Creating Vector...$(BLUE)"
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
