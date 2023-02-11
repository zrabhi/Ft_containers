# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 06:33:45 by zrabhi            #+#    #+#              #
#    Updated: 2023/02/11 18:00:14 by zrabhi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



BLUE 	:= \033[1;34m
SRC 	:= map_tests.cpp 
CC 		:= clang++
RM 		:= rm -f
OBJ		:= $(SRC:%.cpp=%.o)
FLAG	:= -Wall -Werror -Wextra -std=c++98 -g
STD 	:=  -D STL=1
FT		:=	-D STL=0
NAME 	:= FTmap
STL 	:= STDmap
HEADERS := Map.hpp

all: $(NAME)
	@echo ""
	@echo " \n$(BLUE)Creating Map...$(BLUE)"
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